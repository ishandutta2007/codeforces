#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define N 100005
typedef long long LL;

int n ,  a[N] , d;
bool f[N * 5];
int p[N * 5] , q[N * 5];
int main()
{
    int i , j , x , y = 0;
    cin >> n >> d;
    f[0] = 1;
    for (i = 0 ; i < n ; ++ i)
    {
        cin >> x , y += x;
        for (j = y ; j >= x ; -- j)
            f[j] |= f[j - x];
    }
    int top = 0 , bot = 0;
    for (i = 1 ; i <= y ; ++ i) p[i] = 1 << 30;
    for (i = 1 ; i <= y ; ++ i) if (f[i])
    {
        //p[i] = 1 << 30;
        while (top <= bot && q[top] < i - d)
            ++ top;
        if (top <= bot) p[i] = p[q[top]] + 1;
        while (top <= bot && p[i] < p[q[bot]])
            -- bot;
        q[++ bot] = i;
    }
    for (i = y ; i >= 0 ; -- i)
        if (f[i] && p[i] < 1 << 30)
            break;
    cout << i << ' ' << p[i] << endl;
    return 0;
}