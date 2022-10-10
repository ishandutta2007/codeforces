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

long long a[200005];
int b[200005], in[200005];
bool visited[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        if (b[i] != -1)
            in[b[i]]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++)
        if (in[i] == 0)
            q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        if (b[u] != -1 && --in[b[u]] == 0)
            q.push(b[u]);
    }

    long long ret = 0;
    vector<int> act;
    for (int x : order)
        if (a[x] >= 0) {
            visited[x] = true;
            act.push_back(x);
            ret += a[x];
            if (b[x] != -1)
                a[b[x]] += a[x];
        }
    for (int i=n-1; i>=0; i--)
        if (a[order[i]] < 0 && !visited[order[i]]) {
            act.push_back(order[i]);
            ret += a[order[i]];
            if (b[order[i]] != -1)
                a[b[order[i]]] += a[order[i]];
        }

    cout << ret << "\n";
    for (int x : act)
        cout << x << " ";
    cout << "\n";

    return 0;
}