#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool need[1005000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string ret="";
    int one=0,zer=0;
    for (int i=0;i<s.size();i++){
        if (s[i]!=t[i]){
            ret+=s[i];
            if (s[i]=='0')zer++;
            else one++;
        }
         
    }
    int ans=0;
    int sum=0;
    int mn=1e9,mx=-1e9;
    for (int i=0;i<ret.size();i++){
        if (ret[i]=='1')sum++;
        else sum--;
        mn=min(mn, sum);
        mx=max(mx, sum);
        ans=max(ans, max(sum - mn, mx - sum));
    }
    if (zer!=one)ans=-1;
    cout<<ans<<endl;
}