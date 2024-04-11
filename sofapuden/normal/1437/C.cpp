#include<bits/stdc++.h>

using namespace std;
const int MX = 1e8;

int main() {
int t; cin >> t;
while(t--) {
int n; cin >>n;
vector<int>v(n) ;
for(auto & x : v) cin >>x;
sort(v.begin(), v.end());
vector<vector<int>> dp(n, vector<int>(3*n, MX));
for(int i = 1; i <3*n; ++i) {
dp[0][i] = min(dp[0][i-1], abs(i-v[0])) ;
}
for(int i = 1; i < n; ++i) {
for(int j = i+1; j < 3*n; ++j) {
dp[i][j] = min(dp[i-1][j-1]+abs(j-v[i]),dp[i][j-1]);
}
} 
cout << *min_element(dp.back().begin(),dp.back().end()) << '\n' ;
} 
}