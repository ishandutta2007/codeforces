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
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define str string
char s[maxn];
int ed[27];

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%s", s);
        int l = strlen(s);
        memset(ed, -1, sizeof(ed));
        for (int i = 0; i < l; i++)
            chkmax(ed[s[i] - 'a'], i);
        int me = l;
        for (int i = 0; i < 26; i++)
            if (ed[i] != -1) chkmin(me, ed[i]);
        for (int j = me; j < l; j++)
            printf("%c", s[j]);
        printf("\n");
    }
    return (0-0); //<3
}