#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll> a[1000000];
bool cmp(pair<ll,ll> A,pair<ll,ll> B){
    return B.first+A.second<B.second+A.first;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n, cmp);
    ll ret=0;
    for (int i=0;i<n;i++) {
        ret+=i*a[i].first + (n-i-1)*a[i].second;
    }
    cout<<ret<<endl;
}