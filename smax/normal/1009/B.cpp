#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = s.length();

    int numOne = 0;
    for (char c : s)
        if (c == '1')
            numOne++;

    int brk = n - numOne;
    string t(numOne, '1');
    for (int i=0, j=0; i<n; i++)
        if (s[i] != '1') {
            j++;
            t += s[i];
            if (s[i] == '2' && brk == n - numOne)
                brk = j;
        }

    sort(t.begin(), t.begin() + brk + numOne);
    cout << t << "\n";

//    char pred = s[0];
//    for (int i=1, j=0, k=-1; i<n; i++) {
//        bool sw = false;
//        if (s[i] == '0') {
//            sw = (pred == 1);
//            if (pred == 2 && k == -1)
//                k = i;
//        }
//        else
//            sw = (pred != s[i]);
//        DEBUG(s[i], i, sw)
//        if (sw) {
//            if (s[i] + 1 == pred) {
//                swap(s[i], s[j++]);
//                if (k != -1) {
//                    swap(s[i], s[k]);
//                    k = -1;
//                }
//            }
//            else {
//                j = i;
//                pred = s[i];
//            }
//        }
//    }
//
//    cout << s << "\n";

//    string t;
//    vector<vector<int>> group(3);
//    for (int i=0; i<n; i++) {
//        int cnt = 1;
//        while (i < n - 1 && s[i+1] == s[i])
//            cnt++, i++;
//        t += s[i];
//        group[s[i]-'0'].push_back(cnt);
//    }
//
//    DEBUG(t)
//    for (int i=0; i<(int)t.length()-1; i++)
//        if (t[i] == t[i+1] + 1 || (i < (int) t.length() - 2 && t[i+2] + 1 == t[i] && t[i] + 1 == t[i+1]))
//            swap(t[i], t[i+1]);
//    DEBUG(t)
//
//    vector<int> ptr(3);
//    for (char c : t) {
//        assert(ptr[c-'0'] < group[c-'0'].size());
//        for (int i=0; i<group[c-'0'][ptr[c-'0']]; i++)
//            cout << c;
//        ptr[c-'0']++;
//    }
//    cout << "\n";

    return 0;
}