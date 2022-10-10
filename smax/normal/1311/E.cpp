#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> par(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({1, 0});
        pq.push({1, 0});
        long long ret = 0;
        for (int i=1; i<n; i++) {
            auto p = pq.top();
            pq.pop();

//            par[i] = p.second;
            ret += p.first;
            pq.push({p.first + 1, i});
            pq.push({p.first + 1, i});
        }

        if (d < ret)
            cout << "NO\n";
        else {
//            cout << "YES\n";
            priority_queue<pair<int, int>> pq2;
            pq2.push({0, 0});
            multiset<pair<int, int>> st{{1, 0}};
            ret = 0;
            for (int i=1; i<n; i++) {
                ret += i;
                par[i] = i - 1;
                st.insert({i + 1, i});
                pq2.push({i, i});
            }
            if (d > ret) {
                cout << "NO\n";
                continue;
            }

            while (ret > d) {
                auto p = pq2.top();
                pq2.pop();

                long long diff = ret - d;
                auto it = st.lower_bound({max(p.first - diff, 0LL), -1});
                assert(it != st.end());
                auto q = *it;
                DEBUG(p, q)
                st.erase(it);
                ret += q.first - p.first;
                par[p.second] = q.second;
                pq2.push({q.first, p.second});
                st.insert({q.first + 1, p.second});
                st.insert({q.first + 1, p.second});
            }

            cout << "YES\n";
            for (int i=1; i<n; i++)
                cout << par[i] + 1 << " \n"[i==n-1];
        }
    }

    return 0;
}