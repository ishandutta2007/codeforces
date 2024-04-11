#include <stdio.h>
#include <algorithm>
#define N 70010

using namespace std;

int cnt[N];
int f[N], id[N], p[N];
int a[N], ans[N], Q[N];
int res[N], ID[N], revID[N];
bool fl[N];

bool cmp(int x, int y) { return a[x]<a[y]; }

bool cmp1(int x, int y) { return a[x]>a[y]; }

int main() {
    int n, s, i, j, m, cur, pre, Cnt=0, num, k;
    int maxid;
//  freopen ("in3.txt", "r", stdin);
    scanf("%d %d", &n, &s);
    for (i=1; i<=n; i++) {
        scanf("%d", a+i);
        cnt[a[i]]++;
        id[i]=i;
    }
    sort(id+1, id+n+1, cmp);
    s-=a[id[n]];if (s<0) {puts("-1");return 0;}
    maxid=id[n];
    cnt[a[id[n]]]--;
    f[0]=1;
    for (i=1; i<=a[id[n]] && !f[s]; i++) {
        if (!cnt[i]) continue;
        for (j=s-i; j>=0; j--) {
            if (f[j]) {
                m=j;
                for (k=0; k<cnt[i]; k++) {
                    m+=i;
                    if (m>s || f[m]) break;
                    f[m]=1, p[m]=m-i;
                }
            }
        }
    }
    if (!f[s]) {
        puts("-1");
        return 0;
    }
    cur=s;
    while (cur) {
        pre=p[cur];
        Q[cur-pre]++;
        cur=pre;
    }
    fl[maxid]=0, Cnt=0;
    for (i=1; i<=n; i++) {
        if (Q[a[i]]) {
            fl[i]=1;
            Q[a[i]]--;
        }
    }
    for (i=1; i<=n; i++) if (!fl[i]) ID[Cnt++]=i;
    sort(ID, ID+Cnt, cmp1);
    for (i=0; i<Cnt; i++) revID[ID[i]]=i;
    for (i=1; i<=n; i++) {
        if (fl[i]) printf("%d 0\n", a[i]);
        else {
            j=revID[i];
            if (j==Cnt-1) printf("%d 0\n", a[i]);
            else printf("%d 1 %d\n", a[i]-a[ID[j+1]], ID[j+1]);
        }
    }
}