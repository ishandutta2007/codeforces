#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double logfact[MAXN];
int n,m,k;
int main()
{
    logfact[0]=0.0;
    for(int i=1;i<=200000;i++) logfact[i]=logfact[i-1]+log(i);
    scanf("%d%d%d",&n,&m,&k);
    if(n+k<m) puts("0");
    else if(k>=m) puts("1");
    else
    {
        double res=logfact[m]+logfact[n]-logfact[m-k-1]-logfact[n+k+1];
        printf("%.10f\n",1.0-exp(res));
    }
    return 0;
}