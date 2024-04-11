#include<bits/stdc++.h>
using namespace std;
string s[1009],t[1009];
main(){
    int n,m,q;
    cin>>n>>m;
    for(int i =1 ;i <= n; i++)
        cin>>s[i-1];
    for(int j = 1; j <= m; j++)
        cin>>t[j-1];
    cin>>q;
    while(q--){
        int y;
        cin >> y;y--;
        cout<<s[y%n]<<t[y%m]<<endl;
    }
}