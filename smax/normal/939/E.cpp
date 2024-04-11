#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int x, cnt = 1;
    double sum = 0;
    queue<int> q;
    for (int i=0; i<n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> x;
            q.push(x);
        } else {
            while (!q.empty() && q.front() < (x + sum) / cnt) {
                sum += q.front();
                cnt++;
                q.pop();
            }
            cout << fixed << setprecision(10) << x - (x + sum) / cnt << "\n";
        }
    }

    return 0;
}