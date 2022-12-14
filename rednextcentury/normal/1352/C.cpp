#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        k--;
        ll need = k/(n-1);
        ll extra = k%(n-1);
        cout<<n*need + extra + 1<<endl;
    }
}