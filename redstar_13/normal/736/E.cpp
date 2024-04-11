#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN 3030

pii p[NN];
int sum[NN];
char ans[NN][NN], ch[]="LDW";

void update(int u, int v, int c) {
    p[u].second -= c; p[v].second -= 2-c;
    ans[p[u].first][p[v].first]=ch[c];
    ans[p[v].first][p[u].first]=ch[2-c];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int m, n;
    cin>>m>>n;
    for (int i=1; i<=m; i++) {
        p[i].first = i;
        ans[i][i]='X';
        sum[i]=sum[i-1]+(m-i<<1);
    }

    int pnt = 0;
    for (int i=1; i<=n; i++) {
        cin>>p[i].second;
        pnt+=p[i].second;
        if (pnt>sum[i]) return puts("no");
    }
    if (sum[m]>pnt+p[n].second*(m-n)) return puts("no");
    puts("yes");
    
    for (int i=n+1; i<=m; i++) {
        p[i].second = (sum[m]-pnt+m-i)/(m-i+1);
        pnt += p[i].second;
    }

    for (int i=1; i<=m; i++) {
        sort(p+i, p+m+1, [&](pii a, pii b) {return a.second>b.second;});
        for (int j=i+1; j<=m; j++) {
            if (p[i].second==(m-j+1<<1)) update(i, j, 2);
            else if (p[i].second+1==(m-j+1<<1)) update(i, j, max(1, 2-p[j].second));
            else update(i, j, max(0, 2-p[j].second));
        }
    }

    for (int i=1; i<=m; i++) puts(ans[i]+1);

    return 0;
}