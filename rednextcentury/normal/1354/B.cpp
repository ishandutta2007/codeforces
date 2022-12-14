#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int last[4];
        for (int i=1;i<=3;i++) last[i]=-1e6;
        int ret = 1e9;
        for (int i=0;i<s.size();i++){
            char x = s[i];
            last[x-'0']=i;
            ret=min(ret, i - min(min(last[1],last[2]),last[3])+1);
        }
        if (ret>s.size())ret=0;
        cout<<ret<<endl;
    }
}