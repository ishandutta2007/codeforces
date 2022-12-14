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
    u = getP(u);
    v = getP(v);
    if (u==v)ok=0;
    num++;
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
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        L[i]=l,R[i]=r;
        add[l]=i;
        add[r]=-i;
    }
    for (int i=1;i<=n;i++)par[i]=i;
    for (int i=1;i<=2*n;i++) {
        int l = L[abs(add[i])], r = R[abs(add[i])];
        if (add[i]>0) {
            for (auto x:s) {
                if (x.first>r)break;
                Merge(add[i],x.second);
                if (!ok)break;
            }
            s.insert({r,add[i]});
        } else {
            s.erase({r,-add[i]});
        }
        if (!ok)break;
    }
    if (ok && num==n-1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}