#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> h(n), ans(n);
        for(int i = 0; i < n; ++i)
            cin >> h[i];

        for(int i = 0; i < m; ++i)
            pq.push({0, i});

        for(int i = 0; i < n; ++i){
            auto [val, idx] = pq.top();
            pq.pop();

            val += h[i];
            ans[i] = idx;
            pq.push({val, idx});
        }

        cout << "YES\n";
        for(int i = 0; i < n; ++i)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }
}