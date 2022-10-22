#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300005;

int n , a[N];
LL s[N];
int pre[3][N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1 ; i <= n ; ++ i) {
        pre[1][i] = pre[1][i - 1];
        pre[2][i] = pre[2][i - 1];
        pre[a[i] / 1000][i] = i;
    }

    LL res = s[n];

    for (int i = 1 ; i <= n ; ++ i) {
        LL dis = s[i] / 10;
        res = min(res , s[n] - min(dis , s[n] - s[i]));

        int x = pre[1][i];
        if (x) {
            assert(a[x] == 1000);
            LL sum = 0;
            sum += s[x - 1];
            dis = sum / 10;
            LL d = min(dis , (LL)a[x]);
            sum += a[x] - d;
            dis -= d;
            sum += s[i] - s[x];
            dis += (s[i] - s[x]) / 10;
            res = min(res , sum + s[n] - s[i] - min(dis , s[n] - s[i]));
            for (int k = 1 ; k <= 2 ; ++ k) {
                int y = pre[k][x - 1];
                if (y) {
                    LL sum = 0;
                    sum += s[y - 1];
                    dis = sum / 10;
                    LL d = min(dis , (LL)a[y]);
                    sum += a[y] - d;
                    dis -= d;
                    sum += s[x - 1] - s[y];
                    dis += (s[x - 1] - s[y]) / 10;
                    d = min(dis , (LL)a[x]);
                    sum += a[x] - d;
                    dis -= d;
                    sum += s[i] - s[x];
                    dis += (s[i] - s[x]) / 10;
                    res = min(res , sum + s[n] - s[i] - min(dis , s[n] - s[i]));
                }
            }
        }
        x = pre[2][i];
        if (x) {
            assert(a[x] == 2000);
            LL sum = 0;
            sum += s[x - 1];
            dis = sum / 10;
            LL d = min(dis , (LL)a[x]);
            sum += a[x] - d;
            dis -= d;
            sum += s[i] - s[x];
            dis += (s[i] - s[x]) / 10;
            res = min(res , sum + s[n] - s[i] - min(dis , s[n] - s[i]));
            for (int k = 1 ; k <= 2 ; ++ k) {
                int y = pre[k][x - 1];
                if (y) {
                    LL sum = 0;
                    sum += s[y - 1];
                    dis = sum / 10;
                    LL d = min(dis , (LL)a[y]);
                    sum += a[y] - d;
                    dis -= d;
                    sum += s[x - 1] - s[y];
                    dis += (s[x - 1] - s[y]) / 10;
                    d = min(dis , (LL)a[x]);
                    sum += a[x] - d;
                    dis -= d;
                    sum += s[i] - s[x];
                    dis += (s[i] - s[x]) / 10;
                    res = min(res , sum + s[n] - s[i] - min(dis , s[n] - s[i]));
                }
            }
        }
    }

    cout << res << endl;

}