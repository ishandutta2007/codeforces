#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        vector<int> lo{0}, hi{0};
        bool change = false;
        for (int i=0; i<n; ) {
            int j = i;
            while (j < n && a[i] == a[j])
                j++;
            if (a[i] == -1) {
                if (change) {
                    lo.push_back(lo.back() - (j - i));
                    hi.push_back(hi.back() + ((j - i) % 2 ? 1 : 0));
                } else {
                    lo.push_back(lo.back() - (j - i));
                    hi.push_back(hi.back() + ((j - i) % 2 ? -1 : 0));
                }
                change = false;
            } else if (a[i] == 1) {
                if (change) {
                    lo.push_back(lo.back() + ((j - i) % 2 ? -1 : 0));
                    hi.push_back(hi.back() + j - i);
                } else {
                    lo.push_back(lo.back() + ((j - i) % 2 ? 1 : 0));
                    hi.push_back(hi.back() + j - i);
                }
                change = false;
            } else {
                change = true;
            }
            i = j;
        }

        if (lo.back() <= 0 && 0 <= hi.back() && lo.back() % 2 == 0) {
            int sum = 0;
            vector<pair<int, int>> ret;
            for (int i=n-1, k=(int)lo.size()-2; i>=0; k--) {
                int j = i;
                while (j >= 0 && a[i] == a[j])
                    j--;
                if (a[i] == 1) {
                    if (sum > hi[k]) {
                        int diff = sum - hi[k];
                        while (--diff) {
                            ret.emplace_back(i, i);
                            i--;
                            sum--;
                        }
                        ret.emplace_back(j + 1, i);
                        sum -= (i - j) % 2;
                    } else {
                        if (sum - (i - j) % 2 >= lo[k]) {
                            ret.emplace_back(j + 1, i);
                            sum -= (i - j) % 2;
                        } else {
                            assert(j >= 0 && a[j] == 0);
                            ret.emplace_back(j, i);
                            sum += (i - j) % 2;
                            j--;
                        }
                    }
                } else if (a[i] == -1) {
                    if (sum < lo[k]) {
                        int diff = lo[k] - sum;
                        while (--diff) {
                            ret.emplace_back(i, i);
                            i--;
                            sum++;
                        }
                        ret.emplace_back(j + 1, i);
                        sum += (i - j) % 2;
                    } else {
                        if (sum + (i - j) % 2 <= hi[k]) {
                            ret.emplace_back(j + 1, i);
                            sum += (i - j) % 2;
                        } else {
                            assert(j >= 0 && a[j] == 0);
                            ret.emplace_back(j, i);
                            sum -= (i - j) % 2;
                            j--;
                        }
                    }
                } else {    // 0
                    ret.emplace_back(j + 1, i);
                    k++;
                }
                i = j;
            }
            reverse(ret.begin(), ret.end());
            cout << ret.size() << "\n";
            for (auto [l, r] : ret)
                cout << l + 1 << " " << r + 1 << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}