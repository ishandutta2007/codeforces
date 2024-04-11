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
const int maxn = 200005;
int t;
int n;
char inp[3][maxn];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt[3][2] = {0};
        for (int i = 0; i < 3; i++) {
            scanf("%s", inp[i] + 1);
            for (int j = 1; j <= 2 * n; j++)
                cnt[i][inp[i][j] - '0']++;
        }
        int flag = 0;
        for (int tp = 0; tp < 2; tp++) {
            for (int i = 0; i < 3; i++)
                for (int j = i + 1; j < 3; j++) {
                    if (flag) break;
                    if (cnt[i][tp] >= n && cnt[j][tp] >= n) {
                        //cout << "OK" << endl;
                        flag = 1;
                        vi cr;
                        vector<vi> s; s.resize(n + 1);
                        int u[2] = {i, j};
                        for (int h = 0; h < 2; h++) {
                            int id = u[h];
                            int sum = 0;
                            for (int m = 1; m <= 2 * n; m++) {
                                int cur = inp[id][m] - '0';
                                if (cur != tp) s[sum].pb(cur);
                                else {
                                    if (sum < n) sum++;
                                    else s[sum].pb(cur);
                                }
                            }
                        }
                        vi res;
                        for (int i = 0; i <= n; i++) {
                            if (i != 0) res.pb(tp);
                            for (auto v : s[i]) res.pb(v);
                        }
                        while (res.size() < 3 * n) res.pb(0);
                        for (auto v : res) printf("%d", v);
                        printf("\n");
                        break;
                    }
                }
        }
    }
    return 0;
}