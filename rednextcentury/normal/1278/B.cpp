#include<bits/stdc++.h>
using namespace std;
#define ll long long
int par[1000000];
int getP(int v){
    if (par[v]==v)return v;
    return par[v]=getP(par[v]);
}
bool ok=1;
int num=0;
void Merge(int u,int v) {
    if (par[u]==par[v])ok=0;
    num++;
    u = getP(u);
    v = getP(v);
    if (rand()%2)swap(u,v);
    par[u]=v;
}
int add[3000000];
set<pair<int,int> > s;
int L[1000000];
int R[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll a, b;
        cin>>a>>b;
        if (a==b){
            cout<<0<<endl;
            continue;
        }
        ll ret = 1e9;
        ll diff = llabs(a-b);
        for (ll i=1;i<=100000;i++) {
            ll x = i*(i+1)/2;
            if (x>=diff && (x-diff)%2==0){
                ret = i;
                break;
            }
        }
        cout<<ret<<endl;
    }
}