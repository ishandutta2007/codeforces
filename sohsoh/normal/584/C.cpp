/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll n, t;
    cin >> n >> t;
    string s1, s2, s = "";
    cin >> s1 >> s2;
    ll same = 0;
    for (int i = 0; i < n; i++) if (s1[i] == s2[i]) same++;
    same = min(same, n - t);
    ll fr = n - t - same, sr = n - t - same;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            if (same > 0) {
                same--;
                s.push_back(s1[i]);
            } else {
                char c = 'a';
                if (c == s1[i]) c++;
                s.push_back(c);
            }
        } else {
            if (fr > 0) {
                fr--;
                s.push_back(s1[i]);
            } else if (sr > 0) {
                sr--;
                s.push_back(s2[i]);
            } else {
                char c = 'a';
                if (c == s1[i]) c++;
                if (c == s2[i]) c++;
                if (c == s1[i]) c++;
                if (c == s2[i]) c++;
                s.push_back(c);
            }
        }
    }

    if (fr > 0 || sr > 0 || same > 0) return cout << -1 << endl, 0;
    cout << s << endl;
    return 0;
}