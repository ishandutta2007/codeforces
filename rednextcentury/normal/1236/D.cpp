#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<int> row[1000000];
set<int> col[1000000];
int main() {
    int r1,r2,c1,c2;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    ll tot = n*1LL*m - k -1;
    for (int i=0;i<k;i++) {
        int x,y;scanf("%d%d",&x,&y);
        row[x].insert(y);
        col[y].insert(x);
    }
    for (int i=1;i<=n;i++)row[i].insert(m+1), row[i].insert(0);
    for (int i=1;i<=m;i++)col[i].insert(n+1), col[i].insert(0);
    int r = 1, c = 1;
    r1=2,r2=n;
    c1=1,c2=m;
    int dir=0;
    if (row[1].count(2))dir=1;
    while(1)
    {
        int cur=0;
        if (dir == 0){
            int nxt = *row[r].upper_bound(c)-1; nxt = min(nxt,c2);
            cur = nxt-c;
            c = nxt;
            c2 = min(c2,nxt-1);
        } else if (dir==1) {
            int nxt = *col[c].upper_bound(r)-1; nxt = min(nxt,r2);
            cur = nxt - r;
            r = nxt;
            r2 = min(r2,nxt-1);
        } else if (dir==2) {
            int nxt = *(--row[r].lower_bound(c))+1; nxt = max(nxt,c1);
            cur = c-nxt;
            c = nxt;
            c1 = max(c1,nxt+1);
        } else if (dir==3) {
            int nxt = *(--col[c].lower_bound(r))+1; nxt = max(nxt,r1);
            cur = r-nxt;
            r = nxt;
            r1 = max(r1,nxt+1);
        }
        dir=dir+1;
        dir%=4;
        if (cur==0)break;
        tot-=cur;
    }
    if (tot==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}