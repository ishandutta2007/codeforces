#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 1005;
char inp[maxn];
char ed[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", inp + 1);
        int ls = -1e9 - 100;
        for (int i = 1; i <= n; i++) {
            if (inp[i] == '1') {
                ls = i;
                ed[i] = '1';
            }
            else if (ls >= i - m) ed[i] = '1';
            else ed[i] = '0';
        }
        ls = n + 1e9 + 100;
        for (int i = n; i >= 1; i--)
            if (inp[i] == '1') {
                ls = i;
                ed[i] = '1';
            }
            else if (ls <= i + m) ed[i] = '1';
        ls = -1;
        for (int i = 1; i <= n; i++) {
            if (inp[i] == '1') {
                if (ls != -1 && (i % 2 == ls % 2))
                    ed[(i + ls) / 2] = '0';
                ls = i;
            }
        }
        for (int i = 1; i <= n; i++) printf("%c", ed[i]);
        printf("\n");
    }
    return 0;
}