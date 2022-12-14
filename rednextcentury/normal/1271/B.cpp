#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> solve(string s){
    vector<int> ret;
    for (int i=0;i+1<s.size();i++) {
        if (s[i]=='W'){
            s[i]='B';
            if (s[i+1]=='W')s[i+1]='B';
            else s[i+1]='W';
            ret.push_back(i+1);
        }
    }
    for (auto x:s)if (x=='W') return {-1};
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    vector<int> ret = solve(s);
    if (ret.size()==0 || ret[0]!=-1) {
        cout<<ret.size()<<endl;
        for (auto x:ret)cout<<x<<' ';
        return 0;
    }
    for (auto &x:s)if (x=='W')x='B'; else x='W';
    ret = solve(s);
    if (ret.size()==0 || ret[0]!=-1) {
        cout<<ret.size()<<endl;
        for (auto x:ret)cout<<x<<' ';
        return 0;
    }
    cout<<-1<<endl;
}