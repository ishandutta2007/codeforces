#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=100005;

int n,pcnt,lev;
int a[maxn],num[maxn];
LL k,ans,nowk;
int f[3][maxn];

void mplus(int which,int num,int flag)
{
    while (num<=n)
    {
        f[which][num]+=flag;
        num+=num&(-num);
    }
}

int getsum(int which,int num)
{
    int s=0;
    while (num>0)
    {
        s+=f[which][num];
        num-=num&(-num);
    }
    return s;
}

int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    pcnt=0;
    for (int i=1;i<=n;i++) num[pcnt++]=a[i];
    sort(num,num+pcnt);
    pcnt=unique(num,num+pcnt)-num;
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(num,num+pcnt,a[i])-num+1;
    //for (int i=1;i<=n;i++) cout<<a[i]<<endl;
    ans=0;
    nowk=0;
    lev=2;
    memset(f,0,sizeof(f));
    for (int i=2;i<=n;i++)
    {
        mplus(2,a[i],1);
        nowk+=(LL)getsum(2,n)-(LL)getsum(2,a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        mplus(1,a[i],1);
        nowk+=(LL)getsum(2,a[i]-1)+(LL)getsum(1,n)-(LL)getsum(1,a[i]);
        while (lev<=i)
        {
            nowk-=(LL)getsum(1,n)-(LL)getsum(1,a[lev])+(LL)getsum(2,a[lev]-1);
            mplus(2,a[lev],-1);
            ++lev;
        }
        while ((lev<=n)&&(nowk>k))
        {
            nowk-=(LL)getsum(1,n)-(LL)getsum(1,a[lev])+(LL)getsum(2,a[lev]-1);
            mplus(2,a[lev],-1);
            ++lev;
        }
        ans+=(LL)n-lev+1;
        //cout<<nowk<<" "<<lev<<endl;
    }
    cout<<ans<<endl;
    return 0;
}