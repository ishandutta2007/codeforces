#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10;
int ax, ay, bx, by, cx, cy;
long long x, y;
string s, ss, p;
vector < int > V;
int main()
{
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    x = (1ll * (ax - bx) * (ax - bx) + 1ll * (ay - by) * (ay - by));
    y = (1ll * (cx - bx) * (cx - bx) + 1ll * (cy - by) * (cy - by));
    int q = 1;
    int abx = (ax - bx);
    int aby = (ay - by);
    int cbx = (cx - bx);
    int cby = (cy - by);
    if (1ll * abx * cby == 1ll * aby * cbx)
        q = 0;
    if (x == y && q == 1)
        return printf("Yes"), 0;
    printf("No");
    return (0);
}