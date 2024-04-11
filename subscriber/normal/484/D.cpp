#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int a[1000111];
long long dp[1000111];
int f1[22][1000111], f2[22][1000111];

int last1[1000111], last2[1000111];
int gg[1000111];

int fm1(int l, int r) {
    int w = gg[r - l + 1];
    return min(f1[w][l], f1[w][r - pw(w) + 1]);
}

int fm2(int l, int r) {
    int w = gg[r - l + 1];
    return max(f2[w][l], f2[w][r - pw(w) + 1]);
}

int main(){
//    freopen(TASK".in","r",stdin);   
//    freopen(TASK".out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    last1[n - 1] = last2[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        last1[i] = last1[i + 1];
        last2[i] = last2[i + 1];

        if (a[i] >= a[i + 1]) last1[i] = i;
        if (a[i] <= a[i + 1]) last2[i] = i;
    }
    for (int i = 0; i < n; i++) f1[0][i] = f2[0][i] = a[i];

    gg[1] = 0;
    for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;

    for (int i = 1; i <= gg[n]; i++) {
        for (int j = 0; j < n; j++) if (j + pw(i) <= n) {
            f1[i][j] = min(f1[i - 1][j], f1[i - 1][j + pw(i - 1)]);
            f2[i][j] = max(f2[i - 1][j], f2[i - 1][j + pw(i - 1)]);
        }
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);

        int j = max(last1[i], last2[i]) - 1;
        if (j < i) j = i;

        long long s1 = fm1(i, j);
        long long s2 = fm2(i, j);

        int it = 0;
        while (j < n) {
            it++;
            if (it > 5) break;
            s1 = min(s1, 1ll * a[j]);
            s2 = max(s2, 1ll * a[j]);

            dp[j + 1] = max(dp[j + 1], dp[i] + s2 - s1);
            j++;
        }
    }
    cout << dp[n] << endl;
    return 0;
}