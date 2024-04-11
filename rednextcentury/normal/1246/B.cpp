#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll Power(ll a,ll b) {
    if (b==0)return 1;
    ll x = Power(a,b/2);
    x = (x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
int p[1000000];
int b[1000000];
int mx = 1e5;
void precalc() {
    for (int i=2;i<=mx;i++) {
        if (p[i])continue;
        b[i]=i;
        for (int j=i+i;j<=mx;j+=i)
            b[j]=(p[j]==0)?i:b[j],p[j]=1;
    }

}
int a[1000000];
ll b1 = 1657 , m1 = 1000002499;
ll b2 = 11329, m2 = 999996131;
pair<ll,ll> Hash(vector<pair<int,int> >& x) {
    ll h1 = 0, h2 = 0;
    for (auto v:x) {
        mod = m1;
        h1 = (h1 + v.second * Power(b1, v.first)) % m1;
        mod = m2;
        h2 = (h2 + v.second * Power(b2, v.first)) % m2;
    }
    return {h1, h2};
}
int n,k;
vector<pair<int,int> > factorize(int x) {
    vector<pair<int,int> > vec;
    int lst=-1;
    int num=0;
    while(x!=1) {
        int v = b[x];
        if (v!=lst){
            num%=k;
            if (num)vec.emplace_back(lst,num);
            lst=v;
            num=1;
        } else {
            num++;
        }
        x/=v;
    }
    num%=k;
    if (num)vec.emplace_back(lst,num);
    return vec;
}
map<pair<ll,ll>,ll> mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precalc();
    cin>>n>>k;
    ll ret=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        vector<pair<int,int> > pr = factorize(a[i]);
        pair<ll,ll> H = Hash(pr);
        for (auto &x:pr)x.second=k-x.second;
        pair<ll,ll> need = Hash(pr);
        if (mp.count(need))ret+=mp[need];
        mp[H]++;

    }
    cout<<ret<<endl;
}