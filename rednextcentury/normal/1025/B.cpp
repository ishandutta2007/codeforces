#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[1000000];
int n;
ll solve(ll x)
{
    ll y =x;
    vector<int> vec;
    for (ll i=2;i*i<=x;i++) {
        if (x%i==0) {
            vec.push_back(i);
            while(x%i==0)x/=i;
        }
    }
    if (x!=1)vec.push_back(x);
    for (auto d:vec){
        bool ok=1;
        for (int i=2;i<=n;i++) {
            if (a[i].first%d && a[i].second%d)ok=0;
        }
        if (ok)return d;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    cout<<max(solve(a[1].first),solve(a[1].second))<<endl;
}