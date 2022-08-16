#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int s[MX];
int n;

void solve() {
    vector<int> nums[2];
    REP(i, n) {
        nums[s[i]%2].push_back(s[i]);
    }
    REP(i, 2) sort(nums[i].begin(), nums[i].end());
    int p[2] = {int(nums[0].size() - 1), int(nums[1].size() - 1)};
    LL score[2] = {0, 0};
    for (int k = 0; p[0] >= 0 || p[1] >= 0; k=1-k) {
        if (p[k] < 0) { p[1-k]--; continue; }
        if (p[1-k] < 0 || nums[k][p[k]] >= nums[1-k][p[k-1]])
            score[k] += nums[k][p[k]--];
        else 
            p[1-k]--;
    }
    if (score[0] > score[1]) cout << "Alice\n";
    else if (score[1] > score[0]) cout << "Bob\n";
    else cout << "Tie\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>s[i];
        }
        solve();
    }
    
    return 0;
}