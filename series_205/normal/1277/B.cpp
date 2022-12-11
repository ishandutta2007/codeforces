#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int t,n;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int a,ans=0;
        map<int,int> mp={};
        rep(i,n){
            cin>>a;
            int cnt=0;
            while(a%2==0){
                a/=2;
                cnt++;
            }
            ans-=mp[a];
            mp[a]=max(mp[a],cnt);
            ans+=mp[a];
        }
        cout<<ans<<endl;
    }
}