//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 3
#define S 20
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = (1 << 18);
int a[maxn];
char s[maxn];
#define ar3 array<int, 3>

int main() {
    int n;
    cin >> n;
    scanf("%s", s);
    for (int i = 0; i < (1 << n); i++)
        a[i] = s[i] - 'a';
    for (int l = 1; l <= n; l++) {
        int step = 1 << (l - 1);
        vector<ar3> cur;
        for (int j = 0; j < (1 << n); j += (1 << l))
            for (int k = j; k < j + step; k++) {
                cur.pb({a[k], a[k + step], k});
                cur.pb({a[k + step], a[k], k + step});
            }
        sort(cur.begin(), cur.end());
        for (int i = 0; i < cur.size(); ) {
            int j = i;
            while (j < cur.size() && cur[j][0] == cur[i][0] && cur[j][1] == cur[i][1]) 
                j += 1;
            for (int k = i; k < j; k++)
                a[cur[k][2]] = i;
            i = j;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        if (a[i] == 0) {

            for (int t = 0; t < (1 << n); t++)
                printf("%c", s[i ^ t]);
            printf("\n");
            return 0;
        }
    }
    return (0-0); //<3
}
/*
1

4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19*/