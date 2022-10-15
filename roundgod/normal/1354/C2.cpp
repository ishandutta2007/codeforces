#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
const double PI=acos(-1.0);
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        double ang=PI/(2*n);
        printf("%.10f\n",1.0/sin(ang)*cos(ang/2.0));
    }
    return 0;
}