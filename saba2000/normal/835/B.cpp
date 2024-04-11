#include<bits/stdc++.h>
using namespace std;
main(){
    int k;
    string s;
    cin>>k;
    cin >>s;
    int u = 0;
    vector<int> v;
    for(char c : s)
        v.push_back('9' - c), u += c - '0';
    sort(v.rbegin(),v.rend());
    int ans = 0;
    while(u < k)
        u += v[ans], ans++;
    cout<<ans<<endl;

}