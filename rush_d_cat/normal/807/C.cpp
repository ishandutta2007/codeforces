#include <iostream>
using namespace std;
typedef long long LL;

LL x, y, p, q;
LL gcd_ex(LL a ,LL b, LL &x, LL &y)
{
    if(a==0&&b==0) return -1;
    if(b==0) {x=1;y=0;return a;}
    LL d = gcd_ex(b, a%b, y, x);
    y-=a/b*x;
    return d;
}

int T;
int main()
{
    cin >> T;
    while(T--) 
    {
        cin >> x >> y >> p >> q;
        if(p == 0)
        {
            if(x == 0 && y == 0)
            {
                printf("1\n");
            } else if(x == 0 && y != 0) {
                printf("0\n");
            } else {
                printf("-1\n");
            }
            continue;
        }
        if(p == q)
        {
            if(x == 0 && y == 0)
            {
                printf("1\n");
            } else if(x == y && y != 0) {
                printf("0\n");
            } else {
                printf("-1\n");
            }
            continue;
        }
        if(x==0 && y==0)
        {
            printf("%lld\n", q);
            continue;
        }
        LL c1 = (x+p-1)/p;
        LL c2 = (y-x+q-p-1)/(q-p);
        LL k = max(c1, c2);
        //cout << c1 << " " << c2 << endl;
        printf("%lld\n", k*q-y);
    }
}