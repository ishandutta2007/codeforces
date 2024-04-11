#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> vec;
        vector<ll> act;
        for (int i=0;i<n;i++){
            ll x;
            cin>>x;
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        ll X = vec[0]*vec.back();
        for (ll i=2;i*i<=X;i++){
            if (X%i==0){
                if (X/i != i) act.push_back(X/i);
                act.push_back(i);
            }
        }
        sort(act.begin(),act.end());
        if (vec==act)cout<<X<<endl;
        else cout<<-1<<endl;
    }
}