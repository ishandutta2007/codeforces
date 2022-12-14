#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
int adj[4000000][2];
int cur[100];
int V=1;
void pre(int x) {
    for (int i=0;i<31;i++) {
        cur[i] = x%2;
        x/=2;
    }
    reverse(cur, cur+31);
}
void add(int x){
    pre(x);
    int v=1;
    for (int i=0;i<31;i++) {
        if (adj[v][cur[i]]==0)adj[v][cur[i]]=++V;
        v = adj[v][cur[i]];
    }
}
ll dp(int v,int dep) {
    if (adj[v][0]==0 && adj[v][1]==0) return 0;
    else if (adj[v][0]==0)return dp(adj[v][1], dep-1);
    else if (adj[v][1]==0)return dp(adj[v][0], dep-1);
    else {
        ll L = dp(adj[v][0], dep-1);
        ll R = dp(adj[v][1], dep-1);
        if (L<R)L+=(1LL<<dep);
        else R+=(1LL<<dep);
        return max(L,R);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        add(a[i]);
    }
    cout<<dp(1,30)<<endl;
}