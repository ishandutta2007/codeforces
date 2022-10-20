#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    queue<P> que;
    priority_queue<P> pque;
    int cnt = 0;
    bool fir = true;
    vector<bool> used(1000010);
    for (int _ = 0; _ < T; ++_) {
        int t;
        cin >> t;
        if (t == 1) {
            int m;
            cin >> m;
            ++cnt;
            que.push({m, -cnt});
            pque.push({m, -cnt});
        }
        else if (t == 2) {
            while (true) {
                P p = que.front();
                que.pop();
                if (used[-p.second]) continue;
                if (!fir) cout << ' ';
                cout << -p.second;
                fir = false;
                used[-p.second] = true;
                break;
            }
        }
        else {
            while (true) {
                P p = pque.top();
                pque.pop();
                if (used[-p.second]) continue;
                if (!fir) cout << ' ';
                cout << -p.second;
                fir = false;
                used[-p.second] = true;
                break;
            }
        }
    }
    cout << '\n';
    return 0;
}