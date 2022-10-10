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

    int n;
    string l, r;
    cin >> n >> l >> r;

    vector<int> quest;
    vector<vector<int>> cnt(26);
    for (int i=0; i<n; i++) {
        if (l[i] == '?') quest.push_back(i);
        else cnt[l[i]-'a'].push_back(i);
    }

    vector<pair<int, int>> ret;
    vector<int> quest2, leftOverR;
    for (int i=0; i<n; i++) {
        if (r[i] == '?') quest2.push_back(i);
        else if (!cnt[r[i]-'a'].empty()) {
            ret.emplace_back(cnt[r[i]-'a'].back(), i);
            cnt[r[i]-'a'].pop_back();
        } else leftOverR.push_back(i);
    }

    // match quest with leftOverR
    while (!quest.empty() && !leftOverR.empty()) {
        ret.emplace_back(quest.back(), leftOverR.back());
        quest.pop_back();
        leftOverR.pop_back();
    }

    // match quest2 with leftOverL
    vector<int> leftOverL;
    for (int i=0; i<26; i++)
        leftOverL.insert(leftOverL.end(), cnt[i].begin(), cnt[i].end());
    while (!quest2.empty() && !leftOverL.empty()) {
        ret.emplace_back(leftOverL.back(), quest2.back());
        quest2.pop_back();
        leftOverL.pop_back();
    }

    // match quest with quest2
    while (!quest.empty() && !quest2.empty()) {
        ret.emplace_back(quest.back(), quest2.back());
        quest.pop_back();
        quest2.pop_back();
    }

    cout << ret.size() << "\n";
    for (auto &p : ret)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}