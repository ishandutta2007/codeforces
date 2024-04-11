#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,r;
const double PI=3.1415926535;
int main()
{
    scanf("%d%d",&n,&r);
    double ang=PI/n;
    printf("%.10f\n",r*sin(ang)/(1-sin(ang)));
    return 0;
}