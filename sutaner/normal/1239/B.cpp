#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 400019
//#define DEBUG
using namespace std;

int n;
char s[maxn];
int a[maxn];

void solve(int mi, int l, int r, int& ans, int& ll, int& rr){
    int left = -1, right = -1;
    rep(i, l, r) if (s[i] == '(') {left = i; break;} 
    per(i, r + 1, l) if (i <= n && s[i] == ')') {right = i; break;}
    if (left == -1 || right == -1) return;
    int anss = 0;
    srep(i, left, right) if (a[i] == mi + 2) anss++;
    if (anss > ans) ans = anss, ll = left, rr = right;
}

void solve2(int mi, int l, int r, int& ans, int& ll, int& rr){
    int left = -1, right = -1;
    rep(i, l, r) if (s[i] == '(') {left = i; break;} 
    per(i, r + 1, l) if (i <= n && s[i] == ')') {right = i; break;}
    if (left == -1 || right == -1) return;
    int anss = 0;
    srep(i, left, right) if (a[i] == mi + 1) anss++;
    if (anss > ans) ans = anss, ll = left, rr = right;
}

int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    int mi = n + 1;
    rep(i, 1, n) a[i] = a[i - 1] + ((s[i] == '(') ? 1 : -1), mi = min(mi, a[i]); //printf("%d ", a[i]); printf("\n");
    #ifdef DEBUG
        rep(i, 1, n) printf("%d ", a[i]); printf("\n");
    #endif
    //printf("%d\n", mi);

    if (a[n] != 0) {
        printf("0\n1 1");
        return 0;
    }
    // ansmi == mi + 2;
    int left = -1, right = -1, ans0 = 0, l0 = 0, r0 = 0;
    rep(i, 1, n) if (a[i] == mi || a[i] == mi + 1) {left = i; break;}
    per(i, n, 1) if (a[i] == mi || a[i] == mi + 1) {right = i + 1; break;}
    srep(i, 1, left) if (a[i] == mi + 2) ans0++;
    per(i, n, right) if (a[i] == mi + 2) ans0++;
    rep(i, 1, n) if (a[i] == mi) ans0++;
    l0 = left, r0 = right;
    if (right == n + 1) ans0 = -1;
    // ansmi == mi + 1;
    left = -1, right = -1; int ans1 = 0, l1 = 0, r1 = 0;
    rep(i, 1, n) if (a[i] == mi) {left = i; break;}
    per(i, n, 1) if (a[i] == mi) {right = i + 1; break;}
    srep(i, 1, left) if (a[i] == mi + 1) ans1++;
    per(i, n, right) if (a[i] == mi + 1) ans1++;
    l1 = left, r1 = right;
    if (right == n + 1) ans1 = -1;
    // ansmi == mi;
    int ans2 = 0, l2 = 1, r2 = 1;
    rep(i, 1, n){
        while (i <= n && (a[i] == mi || a[i] == mi + 1)) i++; int l = i;
        while (i <= n && (a[i] != mi && a[i] != mi + 1)) i++; i--; int r = i;
        solve(mi, l, r, ans2, l2, r2);
    }
    rep(i, 1, n) if (a[i] == mi) ans2++;
    // ansmi == mi - 1;
    int ans3 = 0, l3 = 0, r3 = 0;
    rep(i, 1, n){
        while (i <= n && a[i] == mi) i++; int l = i;
        while (i <= n && a[i] != mi) i++; i--; int r = i;
        solve2(mi, l, r, ans3, l3, r3);
    }

    if (ans0 >= max(max(ans1, ans2), ans3)) printf("%d\n%d %d", ans0, l0, r0);
    else if (ans1 >= max(ans0, max(ans2, ans3))) printf("%d\n%d %d", ans1, l1, r1);
    else if (ans2 >= max(ans0, max(ans1, ans3))) printf("%d\n%d %d", ans2, l2, r2);
    else if (ans3 >= max(ans0, max(ans1, ans2))) printf("%d\n%d %d", ans3, l3, r3);
    return 0;
}