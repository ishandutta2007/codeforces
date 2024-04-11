#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 300005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum += a[i];
        sort(a + 1, a + n + 1);
        int flag = 0;
        if (a[n] * 2 >= sum + 1) flag = 1;
        else flag = sum % 2;
        if (flag) cout << "T" << endl;
        else cout << "HL" << endl;
    }
    return 0;
}
//can't first x the