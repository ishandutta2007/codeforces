#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <time.h>
using namespace std;
typedef long long ll;

#define  M 200001



ll k[M],l[M],id[M],kk[M],L[M];
int n;
 ll x1,x2,y1,y2;

bool cmp(int x,int y) {
    if(kk[x] * x1 + L[x]!=kk[y]*x1 + L[y]) return kk[x] * x1 + L[x]<kk[y]*x1 + L[y];
    if(kk[x] * x2 + L[x]!=kk[y]*x2 + L[y]) return kk[x] * x2 + L[x]<kk[y]*x2 + L[y];
    return 0;
}

int main() {
    ///freopen("2.in","r",stdin);
    srand(1002345314);
    scanf("%d",&n);

    scanf("%I64d %I64d",&x1,&x2);
    for(int i=0;i<n;i++) {
        scanf("%I64d %I64d",&kk[i],&L[i]);
    }
    for(int i=0;i<n;i++) id[i] = i;
    sort(id,id+n,cmp);
    ///random_shuffle(id,id+n);
    for(int i=0;i<n;i++) k[i]=kk[id[i]],l[i] = L[id[i]];
    bool ok = 0;
    for(int a=0;a<n;a++) for(int b=a+1;b<n&&b<a+500;b++){
        if(clock()>0.99*CLOCKS_PER_SEC) goto END;
        if(k[a]>k[b]) {
            if(x1 * (k[a] - k[b]) < l[b] - l[a] && l[b] - l[a] < x2* (k[a]-k[b])) {ok =1;break;}
        }
        else {
            if(x1 * (k[a] - k[b]) > l[b] - l[a] && l[b] - l[a] > x2* (k[a]-k[b])) {ok =1;break;}
        }
    }
    END:;
    if(ok) puts("YES");
    else puts("NO");
}