#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> s[5];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int w,t;
        cin>>t>>w;
        s[t].push_back(w);
    }
    sort(s[1].begin(),s[1].end());
    sort(s[2].begin(),s[2].end());
    reverse(s[1].begin(),s[1].end());
    reverse(s[2].begin(),s[2].end());
    int ret=1e9;
    for (int l=0;l<=s[1].size();l++){
        for (int r=0;r<=s[2].size();r++){
            ll W=0;
            for (int x=l;x<s[1].size();x++)W+=s[1][x];
            for (int x=r;x<s[2].size();x++)W+=s[2][x];
            if (W<=l+r*2)ret=min(ret,l+r*2);
        }
    }
    cout<<ret<<endl;
}