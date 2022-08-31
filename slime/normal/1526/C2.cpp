#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 200005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    priority_queue<int> x;
    ll cur = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 0) cur += a[i], cnt += 1;
        else {
            if (cur + a[i] >= 0) {
                cur += a[i];
                cnt += 1;
                x.push(-a[i]);
            }
            else {
                if (!x.empty()) {
                    int cr = x.top(); x.pop();
                    cur += cr;
                    int u = -a[i];
                    cur -= min(cr, u);
                    x.push(min(cr, u));
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}