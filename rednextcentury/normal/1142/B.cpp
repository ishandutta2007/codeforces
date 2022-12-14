#include<bits/stdc++.h>
using namespace std;
#define ll long long
int change[1000000];
int a[1000000];
int b[1000000];
int nxt[1000000][22];
int lst[1000000];
int best[1000000];
vector<pair<int,int> > Q[1000000];
int ans[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        change[a[i]]=i;
    }
    for (int i=1;i<=m;i++) {
        cin>>b[i];
        b[i]=change[b[i]];
    }
    for (int i=m;i>=1;i--) {
        int need = b[i]+1;
        if (need>n)need=1;
        if (lst[need]){
            nxt[i][0]=lst[need];
        }
        lst[b[i]]=i;
    }
    for (int i=1;i<=20;i++) {
        for (int j=1;j<=m;j++) {
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
        }
    }
    for (int i=1;i<=m;i++) {
        int v=i;
        for (int j=0;j<20;j++) {
            if ((1<<j)&(n-1))
                v=nxt[v][j];
        }
        best[i]=v;
    }
    for (int i=1;i<=q;i++) {
        int l,r;
        cin>>l>>r;
        Q[l].emplace_back(r,i);
    }
    int cur = 1e9;
    for (int i=m;i>=1;i--) {
        if (best[i]!=0)
            cur=min(cur,best[i]);
        for (auto p:Q[i]){
            if (cur<=p.first)ans[p.second]=1;
        }
    }
    for (int i=1;i<=q;i++)cout<<ans[i];
    cout<<endl;
}