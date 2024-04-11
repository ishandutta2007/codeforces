#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<string> all;
    for (int i=1;i<=s.size();i++) {
        string x = "";
        for (int j=0;j<k;j++) {
            x += s[j%i];
        }
        all.push_back(x);
    }
    sort(all.begin(),all.end());
    cout<<all[0]<<endl;
}