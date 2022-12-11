#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

typedef int ll;
typedef long double ld;
#define ff first
#define ss second
const ll N = 1e5 + 34;

string s[N], k[N];
string cur;
char ss[51], kk[51];
int n, p[N], ls, lk;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", ss, kk);
        ls = strlen(ss);
        lk = strlen(kk);
        for (int j = 0; j < ls; j++)
            s[i] += ss[j];
        for (int j = 0; j < lk; j++)
            k[i] += kk[j];
        if (s[i] > k[i])
            swap(s[i], k[i]);
        //printf("%d", strcmp(s[i], k[i]));
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    cur = s[p[0]];
    for (int i = 1; i < n; i++) {
        if (k[p[i]] < cur) {
            printf("NO\n");
            return 0;
        }
        if (s[p[i]] > cur)
            cur = s[p[i]];
        else
            cur = k[p[i]];
    }
    printf("YES\n");
    return 0;
}