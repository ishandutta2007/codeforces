#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k,s;
    cin>>n>>k>>s;
    vector<ll> moves;
    ll cur=1;
    for (int i=1;i<=k;i++){
        if (cur==1){
            if (n-1 <= s-(k-i)){
                s -= n-1;
                cur=n;
                moves.push_back(cur);
            } else {
                ll need  = (s-(k-i));
                if (need<=0){
                    cout<<"NO"<<endl;
                    return 0;
                }
                cur += need;
                moves.push_back(cur);
                s-=need;
            }
        } else {
            if (n-1 <= s-(k-i)){
                s -= n-1;
                cur=1;
                moves.push_back(cur);
            } else {
                ll need  = (s-(k-i));
                if (need<=0){
                    cout<<"NO"<<endl;
                    return 0;
                }
                cur -= need;
                moves.push_back(cur);
                s-=need;
            }
        }
    }
    if (s==0){
        cout<<"YES"<<endl;
        for (auto x:moves)cout<<x<<' ';
        cout<<endl;
    } else cout<<"NO"<<endl;
}