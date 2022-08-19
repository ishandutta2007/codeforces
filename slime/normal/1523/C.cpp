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
int t;
int n;
int a[maxn];
vi cr[maxn];
int fl[maxn];
int st[maxn];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            scanf("%d", &a[i]);
        cr[1].resize(1); cr[1][0] = 1;
        int top = 0;
        st[top++] = 1;
        memset(fl, 0, sizeof(fl));
        for (int i = 2; i <= n; i++) {
            if (a[i] == 1) {
                cr[i] = cr[i - 1];
                cr[i].pb(a[i]);
                st[top++] = i;
            }
            else {
                while (a[st[top - 1]] != a[i] - 1) top--;
                cr[i] = cr[st[top - 1]];
                top--;
                cr[i][cr[i].size() - 1] = a[i];
                st[top++] = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < cr[i].size(); j++) {
                printf("%d", cr[i][j]);
                if (j == cr[i].size() - 1) printf("\n");
                else printf(".");
            }
        }
    }
    return 0;
}