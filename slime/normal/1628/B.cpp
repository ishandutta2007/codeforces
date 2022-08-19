//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define maxn 100005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
unordered_map<str, int> hv; 
bool chk(vector<str> u) {
    int n = u.size();
    hv.clear();
    for (int i = 0; i < n; i++) {
        str re = u[i];
        reverse(re.begin(), re.end());
        if (re == u[i]) return 1;
        if (hv[re]) return 1;
        re.pop_back();
        if (hv[re]) return 1;
        hv[u[i]] = 1;
    }
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<str> u;
        for (int i = 0; i < n; i++) {
            str cur;
            cin >> cur;
            u.pb(cur);
        }
        if (chk(u)) cout << "YES" << endl;
        else {
            reverse(u.begin(), u.end());
            for (int i = 0; i < u.size(); i++)
                reverse(u[i].begin(), u[i].end());
            if (chk(u)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return (0-0); //<3
}