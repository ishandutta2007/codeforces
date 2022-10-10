#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

string s[2500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k, n;
    cin >> k >> n;
    for (int i=0; i<k; i++)
        cin >> s[i];

    int i, j;
    bool ok = true;
    for (i=0; i<k; i++) {
        for (j=i+1; j<k; j++)
            if (s[i] != s[j]) {
                ok = false;
                break;
            }
        if (!ok)
            break;
    }
    if (ok) {
        swap(s[0][0], s[0][1]);
        cout << s[0] << "\n";
        return 0;
    }

    vector<int> diff;
    for (int p=0; p<n; p++)
        if (s[i][p] != s[j][p])
            diff.push_back(p);
    if (diff.size() > 4) {
        cout << "-1\n";
        return 0;
    }

    for (int p : diff)
        for (int q=0; q<n; q++)
            if (p != q) {
                swap(s[i][p], s[i][q]);
                ok = true;
                vector<int> cntI(26);
                for (int l=0; l<n; l++)
                    cntI[s[i][l]-'a']++;
                for (j=0; j<k; j++)
                    if (i != j) {
                        int d = 0;
                        bool isDistinct = true;
                        vector<int> cntJ(26);
                        for (int l=0; l<n; l++) {
                            if (cntJ[s[j][l]-'a'])
                                isDistinct = false;
                            cntJ[s[j][l]-'a']++;
                            if (s[i][l] != s[j][l])
                                d++;
                        }
                        if (cntI != cntJ || (d != 2 && (d != 0 || (d == 0 && isDistinct)))) {
                            ok = false;
                            break;
                        }
                    }
                if (ok) {
                    cout << s[i] << "\n";
                    return 0;
                }
                swap(s[i][p], s[i][q]);
            }
    cout << "-1\n";

    return 0;
}