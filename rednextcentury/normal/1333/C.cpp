#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
ll pre[1000000];
map<ll,int> mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll ret=0;
    int l=0;
    mp[0]=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        mp[pre[i]]++;
        while(mp[pre[i]]>1){
            mp[pre[l]]--;
            l++;
        }
        ret+=i-l;
    }
    cout<<ret<<endl;

}