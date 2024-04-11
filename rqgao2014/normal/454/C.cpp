#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define rf random_shuffle
#define np next_permutation
using namespace std;

double ans=0.0;
double exp(double x,int y){
    if(!y) return 1.0;
    double res=exp(x,y/2);
    res=res*res;
    if(y&1) res=res*x;
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        double t=(double)i/(double)(m);
        ans=ans+(double)(i)*exp(t,n);
        t=(double)(i-1)/(double)(m);
        ans=ans-(double)(i)*exp(t,n);
    }
    printf("%.9lf\n",ans);
    return 0;
}