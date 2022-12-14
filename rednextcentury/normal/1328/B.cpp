#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        int num=0;
        for (ll i=n-1;i>=0;i--){
            if (num==0){
                if (i*(i-1)/2 >= k)cout<<'a';
                else cout<<'b', k-=i*(i-1)/2, num++;
            } else if (num==1){
                if (i>=k)cout<<'a';
                else cout<<'b', num++;
            } else cout<<'a';
        }
        cout<<endl;
    }
}