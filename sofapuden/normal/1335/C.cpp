#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
void solve() {
    int n; cin >> n;
    set<int> s;
    map<int, int> m;
    vi v;
    rep(i, 0, n) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        s.insert(tmp);
        m[tmp]++;
    }
    int best = 0;
    rep(i, 0, v.size()) {
        best = max(best, m[v[i]]);
    }
    int len = s.size();
    if (len == best) {
        cout << len - 1 << "\n";
        return;
    }
    cout << min(best,len) << "\n";
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}