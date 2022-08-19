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
// b,c a,c a,b
struct ST {
    ST *ch[2];
    int l, r;
    int mx[3][3];
}p[maxn << 1], *root;
int stcnt = 0;
int x[maxn];
void upd(ST *a) {
    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++) {
            a->mx[i][j] = 0;
            for (int k = i; k <= j; k++)
                chkmax(a->mx[i][j], a->ch[0]->mx[i][k] + a->ch[1]->mx[k][j]);
        }
}
void st(ST *a, int s) {
    int u[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++) {
            a->mx[i][j] = 1;
            if (i == j && i == s) a->mx[i][j] = 0;
        }
}
void bdtree(ST *a, int l, int r) {
    a->l = l, a->r = r;
    if (l == r) {
        st(a, x[l]);
        return ;
    }
    int mid = (l + r) >> 1;
    a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
    bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
    upd(a);
}
void upd(ST *a, int p, int t) {
    if (a->l == a->r) {
        st(a, t);
        return ;
    }
    int mid = (a->l + a->r) >> 1;
    if (p <= mid) upd(a->ch[0], p, t);
    else upd(a->ch[1], p, t);
    upd(a);
}
char inp[maxn];
int main() {
    int n, q;
    cin >> n >> q;
    scanf("%s", inp + 1);
    for (int i = 1; i <= n; i++)
        x[i] = inp[i] - 'a';
    root = &p[stcnt++];
    bdtree(root, 1, n);
    while (q--) {
        int p; char u[5];
        scanf("%d%s", &p, u);
        upd(root, p, u[0] - 'a');
        printf("%d\n", n - root->mx[0][2]);
    }
    return (0-0); //<3
}