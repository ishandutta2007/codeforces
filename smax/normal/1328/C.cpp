
// Problem : C. Ternary XOR
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string x;
        cin >> n >> x;
        
        bool alt = false;
        string a(n, '0'), b(n, '0');
        for (int i=0; i<n; i++) {
            if (x[i] == '0')
                a[i] = b[i] = '0';
            else if (x[i] == '1') {
                if (!alt) {
                    a[i] = '1';
                    b[i] = '0';
                    alt = true;
                } else {
                    a[i] = '0';
                    b[i] = '1';
                }
            } else {
                if (!alt)
                    a[i] = b[i] = '1';
                else {
                    a[i] = '0';
                    b[i] = '2';
                }
            }
        }
        
        cout << a << "\n" << b << "\n";
    }

    return 0;
}