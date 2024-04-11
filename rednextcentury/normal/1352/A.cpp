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
        vector<string> ret;
        for (int i=0;i<s.size();i++){
            if (s[i]=='0')continue;
            string cur = "";
            cur+=s[i];
            for (int j=i+1;j<s.size();j++)cur+="0";
            ret.push_back(cur);
        }
        cout<<ret.size()<<endl;
        cout<<ret[0];
        for (int i=1;i<ret.size();i++)cout<<' '<<ret[i];
        cout<<endl;
    }
}