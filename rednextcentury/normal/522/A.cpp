#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ret = 1;
    string a,b,c;
    while(n--){
        cin>>a>>b>>c;
        for (auto &x:a)x=tolower(x);
        for (auto &x:c)x=tolower(x);
        mp[a]=max(mp[a],mp[c]+1);
        ret=max(ret,mp[a]+1);
    }
    cout<<ret<<endl;
}