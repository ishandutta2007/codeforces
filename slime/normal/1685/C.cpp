//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
char a[maxn];

int s[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        scanf("%s", a + 1);
        int l = 2 * n;
        int fs = l + 1, ls = 0, mpl = 0;
        for (int i = 1; i <= l; i++) {
            s[i] = s[i - 1];
            if (a[i] == '(') s[i] += 1;
            else s[i] -= 1;
            if (s[i] < 0) chkmin(fs, i), chkmax(ls, i);
            if (s[i] > s[mpl]) mpl = i;
        }
        if (fs > l) printf("0\n");
        else {
            int fm = -1, fp = 0;
            for (int x = 0; x < fs; x++)
                if (chkmax(fm, s[x]))
                    fp = x;
            int em = -1, ep = 0;
            for (int x = ls + 1; x <= l; x++)
                if (chkmax(em, s[x]))
                    ep = x;
            fm += em;
            int flag = 1;
            for (int x = fs; x <= ls; x++)
                if (s[x] > fm) flag = 0;
            if (flag) {
                printf("1\n");
                printf("%d %d\n", fp + 1, ep);
            }
            else {
                printf("2\n");
                printf("%d %d\n", 1, mpl);
                printf("%d %d\n", mpl + 1, l);
            }
        }
                
    }
    return (0-0); //<3
}