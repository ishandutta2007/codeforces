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

const int base=314159;
const int bigp=3214567;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIII;

priority_queue<PIII> f;
int where[1000005],g[220000];
pair<LL,int> hash[bigp+100000];
int n,m,biao,flag,ll,rr,k,cct;
PIII cs;

void pushpair(int x,int y)
{
    if ((x>n)||(y<1)) return;
    if (x==1) f.push(make_pair(y-1,make_pair(y-2,y))); else
    if (y==n) f.push(make_pair(y-x,make_pair(-x,y))); else
    f.push(make_pair((y-x)/2,make_pair(-x,y)));
}

void mplus(int place,int num)
{
    while (place<=n)
    {
        g[place]+=num;
        place+=place&(-place);
    }
}

int getsum(int place)
{
    int k=0;
    while (place>0)
    {
        k+=g[place];
        place-=place&(-place);
    }
    return k;
}

void goerase(int x,int y)
{
    if (x==1) x-=(y-x);
    LL cs=(LL)x*base+y;
    int e=abs(cs)%bigp;
    while (hash[e].first!=-maxlongint)
    {
        if (hash[e].first==cs)
        {
            hash[e].second++;
            return;
        }
        ++e;
    }
    hash[e].first=cs;
    hash[e].second=1;
}

bool ok(PIII s)
{
    int x=-s.second.first,y=s.second.second;
    LL cs=(LL)x*base+y;
    int e=abs(cs)%bigp;
    while (hash[e].first!=-maxlongint)
    {
        if (hash[e].first==cs)
        {
            if (hash[e].second==0)
                return true;
            else
            {
                hash[e].second--;
                return false;
            }
        }
        e++;
    }
    return true;
}

int main()
{
    //freopen("E.in","r",stdin);
    int left,right,mid;
    scanf("%d %d",&n,&m);
    pushpair(1,n);
    memset(g,0,sizeof(g));
    memset(where,0,sizeof(where));
    for (int i=0;i<bigp+100000;i++) hash[i]=make_pair(-maxlongint,0);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&flag,&biao);
        if (flag==1)
        {
            while (!ok(f.top())) f.pop();
            cs=f.top();f.pop();
            where[biao]=-cs.second.first+cs.first;
            mplus(where[biao],1);
            if (-cs.second.first<=where[biao]-1) pushpair(-cs.second.first,where[biao]-1);
            if (where[biao]+1<=cs.second.second) pushpair(where[biao]+1,cs.second.second);
            printf("%d\n",where[biao]);
        }
        else
        {
            k=where[biao];
            where[biao]=0;
            mplus(k,-1);
            cct=getsum(k);
            left=k;right=n;
            while (left<=right)
            {
                mid=(left+right)/2;
                if (getsum(mid)==cct) left=mid+1; else right=mid-1;
            }
            rr=right;
            left=1;right=k;
            while (left<=right)
            {
                mid=(left+right)/2;
                if (getsum(mid-1)==cct) right=mid-1; else left=mid+1;
            }
            ll=left;
            goerase(ll,k-1);
            goerase(k+1,rr);
            pushpair(ll,rr);
        }
    }

    return 0;
}