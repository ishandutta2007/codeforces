#include<bits/stdc++.h>
using namespace std;
long long xgcd(long long a, long long b, long long &x, long long &y) //Returns GCD of A, B
{
	if(a==0)
	{
		x=0;
		y=1;
		return b;
	}
	long long x1, y1;
	long long d = xgcd(b % a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

long long modular_inverse(long long a, long long m)
{
	long long x, y;
	long long g=xgcd(a, m, x, y);
	if(g!=1)
		return -1;
	else
	{
		x=(x%m + m)%m;
		return x;
	}
}

void shift_solution(long long &x, long long &y, long long a, long long b, long long cnt)
{
	x+=cnt*b;
	y-=cnt*a;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0,long long &g)
{
	g=xgcd(abs(a), abs(b), x0, y0);
	if(c%g!=0)
		return false;
	x0 *= c/g;
	y0 *= c/g;
	if(a<0)
		x0*=-1;
	if(b<0)
		y0*=-1;
	return true;
}

long long find_all_solutions(long long a, long long b, long long c, long long minx, long long maxx, long long miny, long long maxy) //Returns number of solutions with x[minx, maxx], y[miny, maxy]
{
	long long x, y, g;
	if(!find_any_solution(a, b, c, x, y,g))
		return 0;
	a /= g;
	b /= g;

	long long sign_a = a>0 ? +1 : -1;
	long long sign_b = b>0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx) shift_solution(x, y, a, b, sign_b);
	if (x > maxx) return 0;
	long long lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx) shift_solution(x, y, a, b, -sign_b);
	long long rx1 = x;

	shift_solution(x, y, a, b, - (miny - y) / a);
	if (y < miny) shift_solution(x, y, a, b, -sign_a);
	if (y > maxy) return 0;
	long long lx2 = x;

	shift_solution(x, y, a, b, - (maxy - y) / a);
	if (y > maxy) shift_solution(x, y, a, b, sign_a);
	long long rx2 = x;

	if (lx2 > rx2)
		swap (lx2, rx2);
	long long lx = max (lx1, lx2);
	long long rx = min (rx1, rx2);

	return (rx - lx) / abs(b) + 1;
}
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long k;
    cin>>k;
    for (int i=1;i<=2000;i++)
    {
        for (int j=i+1;j<=2000;j++)
        {
            long long x,y,g;
            long long a = j;
            long long b = -i;
            if (find_any_solution(a,b,k,x,y,g))
            {
                a/=g;
                b/=g;
                shift_solution(x,y,a,b,1e9);
                for (int p=31;p>=0;p--)
                {
                    shift_solution(x,y,a,b,-(1LL<<p));
                    if (x<y)
                        shift_solution(x,y,a,b,(1LL<<p));
                }
                shift_solution(x,y,a,b,-1);
                if (x<0 || y<0)continue;
                if (i*1000000LL<y)continue;
                if ((j-i)*1000000LL<(y-x))continue;
                int n = j;
                long long neg = y-x;
                if (neg<j-i)continue;
                cout<<n<<endl;
                neg -= (j-i);
                for (int p=0;p<j-i;p++)
                {
                    if (neg>1000000LL-1)
                        neg-=1000000LL-1,ret[p]-=1000000LL;
                    else
                    {
                        ret[p]-=neg+1;
                        neg=0;
                    }
                }
                long long pos = y;
                for (int p=j-i;p<j;p++)
                {
                    if (pos>1000000LL)
                        pos-=1000000LL,ret[p]=1000000LL;
                    else
                    {
                        ret[p]=pos;
                        break;
                    }
                }
                for (int p=0;p<j;p++)
                    cout<<ret[p]<<' ';
                cout<<endl;
                assert(x*j - y*i == k);
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}
//100990200