#include <bits/stdc++.h>

using namespace std;

vector<int> v;
#define pb push_back

int main() {
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v;
    int num=0;
    for (int i=1; i<=n; i++)
    if (i==a||i==b) v.pb(i); else v.pb(0);
    while (v.size()>2)
    {
        num++;
        vector<int> vv;
        for (int j=0; j<v.size(); j+=2)
        if (v[j]==a&&v[j+1]==b) {cout<<num<<endl; return 0;} else
        if (v[j]==b&&v[j+1]==a) {cout<<num<<endl; return 0;} else
        vv.pb(max(v[j],v[j+1]));
        v=vv;
    }
    cout<<"Final!"<<endl;
}