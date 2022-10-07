#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[300009][26];
void solve(){
    string s,t;
 
    cin >> s >> t;
 
    for(int i = s.size(); i >= 0; i--){
        if(i == s.size()){
        for(int j = 0; j < 26; j ++)
        f[i][j] = -1; continue;} else
        for(int j = 0; j < 26; j++)
            f[i][j] = f[i+1][j];
        f[i][s[i]-'a'] = i;
    }
    int j = 0;
    int ans = 0;
    for(int i = 0; i < t.size(); i++){
        j = f[j][t[i]-'a']+1;
        if(j == 0 ) ans++,i--;
        if(ans > t.size()) break;
    }
    if(ans > t.size())cout<<-1<<endl; else
    cout<<ans+1<<endl;
 
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}