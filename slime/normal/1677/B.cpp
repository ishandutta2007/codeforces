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
const int maxn = 1000005;
char inp[maxn];
int sum[maxn], gr[maxn];
int ok[maxn];
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        scanf("%s", inp + 1);
        int h = n * m;
        for (int i = 1; i <= h; i++) 
            sum[i] = sum[i - 1] + inp[i] - '0';
        for (int i = 1; i <= h; i++) {
            int nx = 0;
            if (i >= m) nx = i - m;
            gr[i] = gr[nx];
            if (sum[i] > sum[nx])
                gr[i] += 1;
        }
        int tot = 0;
        for (int i = 0; i < m; i++) ok[i] = 0;
        for (int i = 1; i <= h; i++) {
            if (inp[i] == '1' && !ok[i % m]) {
                ok[i % m] = 1;
                tot += 1;
            }
            gr[i] += tot;
        }
        for (int i = 1; i <= h; i++)
            printf("%d ", gr[i]);
        printf("\n");
    }
    return 0;
}