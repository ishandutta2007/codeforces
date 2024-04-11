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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (n % k != 0) {
            cout << "-1\n";
            continue;
        }

        vector<int> cnt(26);
        for (char c : s)
            cnt[c-'a']++;
        bool ok = true;
        for (int x : cnt)
            ok &= x % k == 0;
        if (ok) {
            cout << s << "\n";
            continue;
        }

        for (int i=n-1; i>=0; i--) {
            cnt[s[i]-'a']--;
            for (int j=int(s[i]-'a')+1; j<26; j++) {
                cnt[j]++;
                int need = 0;
                for (int l=0; l<26; l++)
                    need += (k - cnt[l] % k) % k;
                if (need <= n - i - 1) {
                    s[i] = char(j + 'a');
                    vector<int> rem;
                    for (int l=0; l<26; l++) {
                        int amt = (k - cnt[l] % k) % k;
                        while (amt--)
                            rem.push_back(l);
                    }
                    while ((int) rem.size() < n - i - 1)
                        rem.push_back(0);
                    sort(rem.begin(), rem.end());
                    for (int l=i+1; l<n; l++)
                        s[l] = char(rem[l-i-1] + 'a');
                    cout << s << "\n";
                    goto done;
                }
                cnt[j]--;
            }
        }
        assert(false);
        done:;
    }

    return 0;
}