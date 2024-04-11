#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,k; cin >> n >> k;
        string S; cin >> S;
        int m=(k+1)/2;
        vector<vector<int>> cnt(m,vector<int>(26,0));
        for (int i=0;i<n;++i){
            ++cnt[(i%k<m?i%k:2*m-(k&1?2:1)-i%k)][S[i]-'a'];
        }
        int ans=0;
        for (int i=0;i<m;++i){
            int sum=0,M=0;
            for (int j=0;j<26;++j){
                sum+=cnt[i][j]; M=max(M,cnt[i][j]);
            }
            ans+=sum-M;
        }
        cout << ans << '\n';
    }
}