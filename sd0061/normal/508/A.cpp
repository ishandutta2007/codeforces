#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;

int n , m , K;
bool f[N][N];

void work() {
    cin >> n >> m >> K;
    int i , x , y;
    for (i = 1 ; i <= K ; ++ i) {
        cin >> x >> y;
        f[x][y] = 1;
        if (f[x - 1][y] && f[x - 1][y - 1] && f[x][y - 1]) break;
        if (f[x + 1][y] && f[x + 1][y + 1] && f[x][y + 1]) break;
        if (f[x - 1][y] && f[x - 1][y + 1] && f[x][y + 1]) break;
        if (f[x + 1][y] && f[x + 1][y - 1] && f[x][y - 1]) break;
    }
    if (i > K)
        i = 0;
    cout << i << endl;
}
int main()
{
    work();
    return 0;
}