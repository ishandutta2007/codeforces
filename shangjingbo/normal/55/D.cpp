#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define maxlen 19
#define maxNumber 50
const int maxLcm=(5*7*8*9);

VI list;
long long f[maxlen+1][maxNumber][maxLcm];
int ID[3000],pw[100];

inline int lcm(int a,int b)
{
    if (a==0) return b;
    if (b==0) return a;
    return a*b/__gcd(a,b);
}

inline void prepare()
{
    list.clear();
    for (int stat=1;stat<1<<9;++stat)
    {
        int d=0;
        for (int dig=1;dig<10;++dig)
        if ((1<<dig-1)&stat) d=lcm(d,dig);
        list.PB(d);
    }
    list.PB(0);
    
    sort(list.begin(),list.end());
    list.erase( unique(list.begin(),list.end()) , list.end() );
    
    for (int i=0;i<list.size();++i)
        ID[list[i]]=i;
    
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    for (int i=0;i<maxlen;++i)
        for (int j=0;j<list.size();++j)
            for (int mod=0;mod<maxLcm;++mod)
            if (f[i][j][mod])
            {
                int xx=mod*10%maxLcm;
                for (int dig=0;dig<10;++dig)
                {
                    if (xx==maxLcm) xx=0;
                    f[i+1][ID[lcm(list[j],dig)]][xx]+=f[i][j][mod];
                    ++xx;
                }
            }
    
    pw[0]=1;
    for (int i=1;i<=20;++i)
        pw[i]=pw[i-1]*10%maxLcm;
}

long long ans;
int a[100],len;

inline void dfs(int step,int now,int mod)
{
    if (step<0)
    {
        if (mod % now==0) ++ans;
        return;
    }
    
    for (int dig=(step==len-1);dig<a[step];++dig)
    {
        for (int j=0;j<list.size();++j)
        {
            int nj=ID[lcm(dig,lcm(now,list[j]))];
            if (!nj) continue;
            for (int mm=0;mm<maxLcm;++mm)
            if (f[step][j][mm])
            {
                int nmod=(mm+mod+dig*pw[step])%maxLcm;
                if (nmod % list[nj]==0) ans+=f[step][j][mm];
            }
        }
    }
    
    dfs(step-1,lcm(now,a[step]),(mod+a[step]*pw[step])%maxLcm);
}

inline long long calc(long long limit)
{
    if (limit<=0) return 0;
    
    len=0;
    while (limit)
    {
        a[len++]=limit%10;
        limit/=10;
    }
    
    ans=0;
    for (int j=1;j<list.size();++j)
        for (int mod=0;mod<maxLcm;++mod)
        if (mod % list[j]==0)
            ans+=f[len-1][j][mod];
    
    dfs(len-1,0,0);
    
    return ans;
}

int main()
{
    prepare();
    
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    int T;
    for (scanf("%d",&T);T--;)
    {
        long long L,R;
        cin >> L >> R;
        cout << calc(R) - calc(L-1) << endl;
    }
    
    return 0;
}