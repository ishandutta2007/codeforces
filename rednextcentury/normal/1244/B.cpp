#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l = 1e9,r=-1;
        for (int i=0;i<s.size();i++){
            if (s[i]=='1')l=min(l,i),r=i;
        }
        if (r==-1)cout<<s.size()<<endl;
        else {
            int ans = n+1;
            ans = max(ans,(n-r-1)+(r-l+1)*2);
            ans = max(ans,l+(r-l+1)*2);
            ans = max(ans,(r+1)*2);
            ans = max(ans,(n-l)*2);
            cout<<ans<<endl;
        }
    }
}