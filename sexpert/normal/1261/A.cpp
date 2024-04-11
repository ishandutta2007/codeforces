#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, k;
    cin >> n >> k;
    string tem;
    while(k > 1) {
        tem += "()";
        k--;
    }
    int m = (n - tem.size())/2;
    for(int i = 0; i < m; i++)
        tem += '(';
    for(int i = 0; i < m; i++)
        tem += ')';
    //cout << "tem = " << tem << endl;
    string s;
    cin >> s;
    vector<ii> moves;
    for(int p = 0; p < n; p++) {
        if(s[p] == tem[p])
            continue;
        for(int r = p + 1; r < n; r++) {
            if(s[r] == tem[p]) {
                moves.push_back({p, r});
                reverse(s.begin() + p, s.begin() + r + 1);
                break;
            }
        }
    }
    //cout << s << '\n';
    cout << moves.size() << '\n';
    for(auto m : moves)
        cout << m.first + 1 << " " << m.second + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}