#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = (ll)1e18;
const int N = (int)1e5 + 50;

int n, x, y;
string str;
ll psum[N], ssum[N];
int pcnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    cin >> x >> y;
    n = str.length();

    if(x > y) {
        swap(x, y);
        reverse(all(str));
    }
    str = " " + str;
    int c[2] = {0, 0};
    ll rsum = 0;
    rep(i, 1, n + 1) {
        if(str[i] == '?') {
            psum[i] += 1LL * c[1] * y;
            ssum[i] += 1LL * c[0] * x;
        } else {
            c[str[i] - '0']++;
            if(str[i] == '0') rsum += 1LL * y * c[1];
            else rsum += 1LL * x * c[0];
        }
        pcnt[i] = pcnt[i - 1] + (str[i] == '?');
    }
//    cout << rsum << endl;

    c[0] = c[1] = 0;
    for(int i = n; i >= 1; i--) {
        if(str[i] == '?') {
            psum[i] += 1LL * c[1] * x;
            ssum[i] += 1LL * c[0] * y;
        } else c[str[i] - '0']++;
    }
    ll ang = INF;
    for(int i = 1; i <= n; i++) psum[i] += psum[i - 1];
    for(int i = n; i >= 1; i--) ssum[i] += ssum[i + 1];
//    cout << str << '\n';
    for(int i = 1; i <= n + 1; i++) {
//        cout << i << " " << psum[i - 1] << " " << ssum[i] << endl;
        ang = min(ang, psum[i - 1] + ssum[i] + 1LL * (pcnt[n] - pcnt[i - 1]) * pcnt[i - 1] * x);
    }
    cout << ang + rsum << '\n';



}