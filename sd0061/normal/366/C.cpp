#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 200005
using namespace std;
typedef long long LL;
int n , K , a[N] , b[N];
int f[101][200001];
const int L = 100000;

void  work()
{
    int i , j , k , x , y , sx = 0 , sy = 0;
    cin >> n >> K;
    for (i = -L ; i <= L ; ++ i) f[0][i + L] = -1 << 30;
    f[0][L] = 0;
    for (i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    for (i = 1 ; i <= n ; ++ i)
        cin >> b[i] , b[i] = a[i] - b[i] * K;

    for (i = 1 ; i <= n ; ++ i)
    {
        x = a[i] , y = b[i];
        for (j = L ; j >= -L ; -- j)
        {
            f[i][j + L] = f[i - 1][j + L];
            if (j - y >= -L)
                f[i][j + L] = max(f[i][j + L] , f[i - 1][j - y + L] + x);
        }
    }
    if (f[n][L] > 0) cout << f[n][L] << endl;
    else cout << -1 << endl;
}


int main()
{
  //  freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}