#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
int dp[101010][27];
string s;
char v[260];
void solve() {
    cin>>s;
    int n = s.length();
    int m;
    cin>>m;
    for(int i=0;i<m;++i){
        string t;
        cin>>t;
        v[t[0]] = t[1];
        v[t[1]] = t[0];
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<26;++j){
            dp[i+1][j] = dp[i][j];
        }
        
        for(int j=0;j<26;++j){
            if(v[s[i]]!=j+'a'){
                
                dp[i+1][s[i]-'a'] = max(dp[i][j] + 1,dp[i+1][s[i]-'a']);
            }
        }
    }
    
    int mx=0;
    for(int i=0;i<26;++i){
        mx=max(dp[n][i],mx);
    }
    cout<<n-mx;
}