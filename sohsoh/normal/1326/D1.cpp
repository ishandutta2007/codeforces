/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;


        int k = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] == s[s.size() - i - 1]) {
                k++;
            } else break;
        }

        string mainpre = "";
        string pre = "";
        for (int i = k; i < s.size() - k; i++) {
            pre.push_back(s[i]);
            string pre2 = pre;
            reverse(all(pre2));
            if (pre2 == pre) {
                mainpre = pre;
            }
        }

        string mainsuff = "";
        string suff = "";
        for (int i = s.size() - k - 1; i >= k; i--) {
            suff.push_back(s[i]);
            string suff2 = suff;
            reverse(all(suff2));
            if (suff == suff2) {
                mainsuff = suff;
            }
        }

//        string res = "";
        string tmp = "";
        for (int i = 0; i < k; i++) {
            tmp.push_back(s[i]);
        }

        if (mainsuff.size() > mainpre.size()) mainpre = mainsuff;

        cout << tmp << mainpre;
        reverse(all(tmp));
        cout << tmp;
        cout << endl;
    }

    return 0;
}