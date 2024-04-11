#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, x;
priority_queue<pair<int,int>> Q;
vector<pair<int,int>> Ans;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        while (!Q.empty()) Q.pop();
        Ans.clear();
        cin >> n;
        for(int i=1; i<=n; ++i) {
            cin >> x;
            if (x > 0) Q.emplace(x, i);
        }
        while (Q.size() > 1) {
            pair<int,int> xa = Q.top(); Q.pop();
            pair<int,int> xb = Q.top(); Q.pop();
            Ans.emplace_back(xa.second, xb.second);
            if (xa.first > 1) Q.emplace(xa.first - 1, xa.second);
            if (xb.first > 1) Q.emplace(xb.first - 1, xb.second);
        }
        cout << Ans.size() << '\n';
        for(auto [u,v] : Ans) cout << u << ' ' << v << '\n';
    }
}