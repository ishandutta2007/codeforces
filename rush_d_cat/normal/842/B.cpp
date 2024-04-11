#include <iostream>
#include <cmath>
using namespace std;
const int NICO = 100000+10;
int R, d, n;
int x[NICO], y[NICO], r[NICO];

int main()
{
    scanf("%d %d %d", &R, &d, &n);
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d %d %d", &x[i], &y[i], &r[i]);

        double dis = sqrt(1.0 * x[i]*x[i] + y[i]*y[i]);
        int ok = (dis - r[i] >= R - d) && (dis + r[i] <= R);
        if(ok) cnt ++;
    }
    printf("%d\n", cnt);
}