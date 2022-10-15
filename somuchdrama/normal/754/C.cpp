#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 100;
const string nwd = " .,!?";
bool kal(char c) {
    return find(nwd.begin(), nwd.end(), c) != nwd.end();
}
int main() {
    string useless;
    int t, n, m;
    cin >> t;
    getline(cin, useless);
    while (t--) {
        cin >> n;
        vector<string> name(n);
        for (auto & i : name)
            cin >> i;
        cin >> m;
        getline(cin, useless);
        vector<string> auth(m), text(m);
        for (int i = 0; i < m; ++i) {
            string cur;
            getline(cin, cur);
            std::stringstream ss(cur);
            getline(ss, auth[i], ':');
            getline(ss, text[i]);
            dbg(auth[i], text[i]);
        }
        vector<std::bitset<MAXN>> noticed(m);
        for (int s = 0; s < m; ++s) {
            for (int i = 0; i < text[s].size(); ++i) {
                for (int j = 0; j < n; ++j) {
                    if (noticed[s][j]) continue;
                    bool ok = true;
                    for (int k = 0; k < name[j].size(); ++k) {
                        int pos = i + k;
                        if (pos >= text[s].size() || text[s][pos] != name[j][k]) {ok = false; break;}
                    }
                    if (ok && 
                        (i == 0 || kal(text[s][i - 1])) && 
                        (i + name[j].size() == text[s].size() || kal(text[s][i + name[j].size()])))
                        noticed[s][j] = 1;
                }
            }
            dbg(s, noticed[s]);
        }
        for (int step = 0, e = count(auth.begin(), auth.end(), "?"); step < e; ++step) {
            int res = -1, who = -1, mes = -1;
            for (int i = 0; i < m; ++i) {
                if (auth[i] != "?") continue;
                int cnt = 0, cw = 0;
                for (int a = 0; a < n; ++a) {
                    if (!noticed[i][a] && (!i || auth[i - 1] != name[a]) && (i == m - 1 || auth[i + 1] != name[a])) {
                        ++cnt;
                        cw = a;
                    }
                }
                if (cnt >= 1) {
                    res = 1;
                    who = cw;
                    mes = i;
                    if (cnt == 1)
                        break;
                } 
            }
            if (res == -1) {
                cout << "Impossible\n";
                goto nexttest;
            } else 
                auth[mes] = name[who];
        }
        for (int i = 0; i < m; ++i)
            cout << auth[i] << ':' << text[i] << '\n';
        nexttest:;
    }

    return 0;
}