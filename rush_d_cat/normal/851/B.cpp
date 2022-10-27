#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long LL;
double ax, ay, bx, by, cx, cy;

int main()
{
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    LL d1 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by) ;
    LL d2 = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy) ;
    LL d3 = (bx - cx) * (bx - cx) + (by - cy) * (by - cy) ;

    int ok = 0;

    if (d1 == d3) 
    {
        ok = 1;
    }

    if ( (ay - by) * (ax - cx) == (ax - bx) * (ay - cy) ) {
        ok = 0;
    }

    printf("%s\n", ok ? "Yes": "No");
}