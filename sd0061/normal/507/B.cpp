#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;

LL R , a , b , c , d;

void work() {
    cin >> R >> a >> b >> c >> d;
    LL dis = (a - c) * (a - c) + (b - d) * (b - d);
    R <<= 1;
    if (dis % (R * R) == 0) {
        LL p = dis / (R * R);
        printf("%d\n" , (int) ceil(sqrt(p)));
    } else
        printf("%d\n" , (int) ceil(sqrt(dis) / R));
}

int main()
{
        work();
    return 0;
}