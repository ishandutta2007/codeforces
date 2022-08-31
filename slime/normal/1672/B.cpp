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
#define maxn 1200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
int t, n;
char a[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", a + 1);
        int l = strlen(a + 1);
        int flag = 1;
        if (a[l] != 'B') flag = 0;
        int sum = 0;
        for (int i = 1; i <= l; i++) {
            if (a[i] == 'B') sum--;
            else sum++;
            if (sum < 0) flag = 0;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return (0-0); //<3
}