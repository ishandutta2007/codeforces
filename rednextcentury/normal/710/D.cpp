#include<bits/stdc++.h>
using namespace std;
#define K first
#define D second
long long lcm(long long a,long long b)
{
    return (a/(__gcd(a,b)))*b;
}
long long L,R;
int negX,negY;
long long gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_solution(long long & x, long long & y, long long a, long long b, long long cnt) {
    x += cnt * b;
    y -= cnt * a;
}

long long find_all_solutions(long long a, long long b, long long c, long long minx, long long maxx, long long miny, long long maxy) {
    long long x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    long long sign_a = a > 0 ? +1 : -1;
    long long sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    long long lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    long long rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    long long lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    long long rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    long long lx = max(lx1, lx2);
    long long rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
long long Intersection(pair<long long,long long> A,pair<long long,long long> B)
{
        long long l,r;
        long long Lx = -1;
        l=0,r=1e10;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if (mid*A.K+A.D>=L)Lx=mid,r=mid-1;
            else l=mid+1;
        }
        long long Rx = -1;
        l=0,r=1e10;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if (mid*A.K+A.D<=R)Rx=mid,l=mid+1;
            else r=mid-1;
        }
        long long Ly = -1;
        l=0,r=1e10;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if (mid*B.K+B.D>=L)Ly=mid,r=mid-1;
            else l=mid+1;
        }
        long long Ry = -1;
        l=0,r=1e10;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if (mid*B.K+B.D<=R)Ry=mid,l=mid+1;
            else r=mid-1;
        }
        return find_all_solutions(A.K,-B.K,B.D-A.D,Lx,Rx,Ly,Ry);

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long A1,A2,B1,B2;
    cin>>A1>>B1>>A2>>B2>>L>>R;
    cout<<Intersection({A1,B1},{A2,B2})<<endl;
}