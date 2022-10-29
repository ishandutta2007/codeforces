#include <iostream>

using namespace std;

typedef long long ll;

const int maxn = 2005;
const int MD = 1000000007;

int cnt[maxn][maxn];
int n, k;

void
add(int &dst, int src)
{
    dst += src;
    while (dst >= MD) {
        dst -= MD;
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cnt[0][1] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int kk = j; kk <= n; kk += j) {
                add(cnt[i + 1][kk], cnt[i][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        add(res, cnt[k][i]);
    }
    cout << res << endl;
    return 0;
}