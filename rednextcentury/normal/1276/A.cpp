#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> vec;
        for (int i=0;i+4<s.size();i++) {
            if (s.substr(i,5)=="twone"){
                s[i+2]='x';
                vec.push_back(i+3);
            }
        }

        for (int i=0;i+2<s.size();i++) {
            if (s.substr(i,3)=="two")vec.push_back(i+2),s[i+1]='x';
        }

        for (int i=0;i+2<s.size();i++) {
            if (s.substr(i,3)=="one")vec.push_back(i+2),s[i+1]='x';
        }
        cout<<vec.size()<<endl;
        for (auto x:vec)cout<<x<<' ';
        cout<<endl;
    }

}