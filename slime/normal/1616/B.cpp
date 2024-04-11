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
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 100005;
char inp[maxn];
int n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        scanf("%s", inp + 1);
        inp[n + 1] = 'z' + 1;
        int p = 0;
        for (int i = 2; i <= n + 1; i++) {
            if (inp[i] > inp[i - 1]) {

                if (inp[1] == inp[i - 1]) p = 1;
                else p = i - 1;
                break;
            }
        }
        if (n >= 2 && inp[1] == inp[2]) p = 1;
        for (int i = 1; i <= p; i++) printf("%c", inp[i]);
        for (int i = p; i >= 1; i--) printf("%c", inp[i]);
        printf("\n");
    }
    return (0-0); //<3
}