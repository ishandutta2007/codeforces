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

pair<int, int> a[500];

void f(int i) {
    auto tmp = a[i];
    a[i] = a[i+2];
    a[i+2] = a[i+1];
    a[i+1] = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int inv = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i].first;
            a[i].second = i;
            for (int j=0; j<i; j++)
                if (a[i].first < a[j].first)
                    inv++;
        }

        sort(a, a + n);
        if (inv % 2)
            for (int i=0; i<n-1; i++) {
                if (a[i].first == a[i+1].first && inv % 2) {
                    swap(a[i], a[i+1]);
                    inv++;
                    break;
                }
            }
        if (inv % 2) {
            cout << "-1\n";
            continue;
        }
        for (int i=0; i<n; i++)
            a[i].first = i;

        vector<int> ret;
        sort(a, a + n, [] (const pair<int, int> &pa, const pair<int, int> &pb) {
            return pa.second < pb.second;
        });
        for (int j=n-1; j>=3; j--) {
            if (a[j].first == j)
                continue;
            int pos = -1;
            for (int i=j-1; i>=0; i--)
                if (a[i].first == j) {
                    pos = i;
                    break;
                }
            if (pos != -1) {
                for (int i=pos; i<j; i++) {
                    if (i + 2 <= j) {
                        ret.push_back(i);
                        f(i);
                    } else {
                        ret.push_back(i-1);
                        f(i-1);
                    }
                }
            }
        }
        bool ok = false;
        for (int rep=0; rep<3; rep++) {
            if (a[0].first == 0 && a[1].first == 1 && a[2].first == 2) {
                ok = true;
                break;
            }
            ret.push_back(0);
            f(0);
        }
        if (ok) {
            assert(ret.size() <= n * n);
            cout << ret.size() << "\n";
            for (int x : ret)
                cout << x + 1 << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}