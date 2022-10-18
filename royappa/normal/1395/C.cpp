#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int n, m;
int memo[201][1<<9];
int a[200], b[200];

int f(int p, int mask) {
    if (p == n) {
        return mask;
    }
    int &res = memo[p][mask];
    if (res != -1) {
        return res;
    }
    res = 1<<9;
    for (int i = 0; i < m; i++) {
        res = min(res, f(p+1, mask | (a[p] & b[i])));
    }
    return res;
}

int main()
{
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << f(0, 0) << endl;
	exit(0);
}