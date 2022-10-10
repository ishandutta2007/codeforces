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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> freq(5005);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        freq[a].push_back(i);
    }

    vector<vector<int>> bucket(k);
    for (int x=1; x<=5000; x++) {
        if ((int) freq[x].size() > k) {
            cout << "NO\n";
            return 0;
        }
        for (int i=0; i<(int)freq[x].size(); i++)
            bucket[i].push_back(freq[x][i]);
    }

    for (int i=k-1, j=0; i>j; i--) {
        if (!bucket[i].empty()) break;
        while ((int) bucket[j].size() == 1)
            j++;
        assert(!bucket[j].empty());
        bucket[i].push_back(bucket[j].back());
        bucket[j].pop_back();
    }

    vector<int> ret(n);
    for (int i=0; i<k; i++) {
        assert(!bucket[i].empty());
        for (int j : bucket[i])
            ret[j] = i;
    }
    cout << "YES\n";
    for (int x : ret)
        cout << x + 1 << " ";
    cout << "\n";

    return 0;
}