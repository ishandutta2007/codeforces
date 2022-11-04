#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define MAX_N 200005

int n;
long long k,sqrk,num,ans=0;
map<long long,long long>app,cant;

inline void Solve()
{
    app[num]++;
    cant[num]+=app[num*k];
    if (k==1 || num==0)
    {
        long long app_=app[num];
        if (app_<3) return;
        if (app_==3) ans++;
        else ans+=(app_-1)*(app_-2)/2;
        return;
    }
    if (num%k>0 || num%sqrk>0) return;
    ans+=app[num/k]*app[num/sqrk]-cant[num/sqrk];
}

inline void Output()
{
    printf("%I64d",ans);
}

inline void Init()
{
    scanf("%d%I64d",&n,&k);
    sqrk=k*k;
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&num);
        Solve();
    }
    Output();
}

int main()
{
    Init();
    
	return 0;
}