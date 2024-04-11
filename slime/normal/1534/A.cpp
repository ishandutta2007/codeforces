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
const int maxn = 55;
char inp[maxn][maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int fl[2] = {0, 0};
        for (int i = 1; i <= n; i++) {
            scanf("%s", inp[i] + 1);
            for (int j = 1; j <= m; j++)
                if (inp[i][j] == 'R')
                    fl[(i + j) % 2] = 1;//, cout << "!!!" << i << ' ' << j << endl;
                else if (inp[i][j] == 'W')
                    fl[(i + j + 1) % 2] = 1;
        }
        if (fl[0] && fl[1]) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            int tp = 0;
            if (fl[1]) tp = 1;
            //cout << tp << endl;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                    if ((i + j + tp) % 2 == 1) printf("W");
                    else printf("R");
                printf("\n");
            }
        }
    }
    return 0;
}