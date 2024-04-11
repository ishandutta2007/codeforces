#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

#define PB push_back
#define MP make_pair

const int maxn      =   205;
const int maxm      =   maxn*maxn/2;
const int iterLimit =   100;
const int inf       =   1000000000;

int d[maxn][maxn],n,m,a[maxm],b[maxm],w[maxm];

inline double calc(double a,double b,double w)
{
    if (a+w<=b) return b;
    if (b+w<=a) return a;
    return (a+b+w)/2;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            d[i][j]=inf;
        }
        d[i][i]=0;
    }
    
    for (int i=0;i<m;++i){
        scanf("%d%d%d",&a[i],&b[i],&w[i]);
        --a[i];--b[i];
        d[a[i]][b[i]]=d[b[i]][a[i]]=min(d[a[i]][b[i]],w[i]);
    }
    
    for (int k=0;k<n;++k){
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }   
        }
    }
    
    double ans=1e100;
    for (int i=0;i<m;++i){
        int currentB=-inf;
        vector< pair<int,int> > event;
        for (int j=0;j<n;++j){
            int x=d[j][a[i]];
            int y=d[j][b[i]];
            event.PB(MP(x,y));
        }
        sort(event.begin(),event.end());
        ans=min(ans,(double)event.back().first);
        double ymax=0;
        for (int j=(int)event.size()-1;j>=0;--j){
            ymax=max(ymax,(double)event[j].second);
            if (j>0){
                ans=min(ans,calc(event[j-1].first,ymax,w[i]));
            }else{
                ans=min(ans,ymax);
            }
        }
    }
    printf("%.10f\n",ans);
    
    return 0;
}