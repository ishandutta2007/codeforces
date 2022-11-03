#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

#define maxn 100005

int x[maxn],y[maxn],id[maxn],now[maxn],op[maxn];
int ans,ansi,ansj,n;

inline bool cmpx(const int &i,const int &j)
{
    return x[i]<x[j];
}

inline bool cmpy(const int &i,const int &j)
{
    return y[i]<y[j];
}

inline void Update(int i,int j)
{
    int t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    if (t<ans){
        ans=t;
        ansi=i;
        ansj=j;
    }
}

inline void solve(int l,int r)
{
    if (r-l<3){
        for (int i=l;i<=r;++i)
            for (int j=i+1;j<=r;++j)
                Update(id[i],id[j]);
        return;
    }
    
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    
    double len=sqrt((double)ans);
    int N=0;
    int xx=id[mid];
    for (int i=l;i<=r;++i){
        int u=id[i];
        if (fabs(x[u]-x[xx])<=len){
            now[N++]=u;
        }
    }
//  puts("----------------------");
    sort(now,now+N,cmpy);
    for (int i=0,j=0;i<N;++i){
        while (j<N && y[now[j]]-y[now[i]]<=len) ++j;
        for (int a=i;a<j;++a)
            for (int b=a+1;b<j;++b)
                Update(now[a],now[b]);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
        if (x[i]<0){
            if (y[i]<0){
                op[i]=4;
            }else{
                op[i]=2;
            }
        }else{
            if (y[i]<0){
                op[i]=3;
            }else{
                op[i]=1;
            }
        }
        x[i]=abs(x[i]);
        y[i]=abs(y[i]);
        id[i]=i;
    }
    
    sort(id,id+n,cmpx);
    
    ans=1000000000;
    solve(0,n-1);
    
//  printf("    %lf\n",sqrt(ans));
    printf("%d %d %d %d\n",ansi+1,op[ansi],ansj+1,5-op[ansj]);
    
    return 0;
}