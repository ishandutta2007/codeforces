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
        string s;
        cin >> s;
        int n = (int) s.size();

        vector<int> cnt(26);
        for (char c : s)
            cnt[c-'a']++;

        int st = -1;
        vector<pair<char, int>> all;
        for (int i=0; i<26; i++) {
            if (cnt[i] > 0)
                all.emplace_back(i + 'a', cnt[i]);
            if (cnt[i] == 1) {
                st = i;
                break;
            }
        }
        if (st != -1) {
            // answer is 0
            cout << char(st + 'a');
            cnt[st]--;
            for (int i=0; i<26; i++)
                for (int j=0; j<cnt[i]; j++)
                    cout << char(i + 'a');
            cout << "\n";
            continue;
        }

        if (all.size() == 1) {
            // all same
            for (int j=0; j<all[0].second; j++)
                cout << all[0].first;
            cout << "\n";
            continue;
        }

        sort(all.begin(), all.end());

        // weird ass shit other case
        string ret1;
        auto old = all;
        if (all.size() == 2) {
            ret1 += all[0].first;
            for (int j=0; j<all[1].second; j++)
                ret1 += all[1].first;
            for (int j=0; j<all[0].second-1; j++)
                ret1 += all[0].first;
        } else {
            ret1 += all[0].first;
            ret1 += all[1].first;
            all[1].second--;
            for (int j=0; j<all[0].second-1; j++)
                ret1 += all[0].first;
            ret1 += all[2].first;
            all[2].second--;
            for (int i=1; i<(int)all.size(); i++)
                for (int j=0; j<all[i].second; j++)
                    ret1 += all[i].first;
        }
        all = old;

        string ret2;
        for (int k=0; k<(int)all.size(); k++) {
            if (all[k].second - 1 <= n - all[k].second + 1) {
                // answer is 1
                vector<bool> spots(n - all[k].second + 1);
                ret2 += all[k].first;
                all[k].second--;
                vector<char> bruh;
                for (int i=0; i<(int)all.size(); i++)
                    if (i != k)
                        for (int j=0; j<all[i].second; j++)
                            bruh.push_back(all[i].first);
                assert(bruh.size() == spots.size() - 1);
                for (int i=0; i<(int)spots.size(); i++)
                    if (all[k].second > 0 && (i == (int) spots.size() - 1 || all[k].first < bruh[i])) {
                        spots[i] = true;
                        all[k].second--;
                    }
                for (int i=(int)spots.size()-1; i>=0; i--)
                    if (all[k].second > 0 && !spots[i]) {
                        spots[i] = true;
                        all[k].second--;
                    }
                assert(all[k].second == 0);
                if (spots[0])
                    ret2 += all[k].first;
                for (int i=1; i<(int)spots.size(); i++) {
                    ret2 += bruh[i-1];
                    if (spots[i])
                        ret2 += all[k].first;
                }
                goto done;
            }
        }
        DEBUG(s, all);
        assert(false);
        done:;

        cout << min(ret1, ret2) << "\n";
    }

    return 0;
}