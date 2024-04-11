/*
ID: Sfiction
OJ: CF
PROB: 492E
*/
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAXN=1000000+100,MAXM=100000+100;

int n,m;
int x,y;
int cnt[MAXN];
vector<int> c[MAXN];

int Comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int u,v;
    for (int i=0;i<m;++i){
        scanf("%d%d",&u,&v);
        c[u].push_back(v);
    }
    int x0=0,y0=0;
    for (int step=0;step<n;++step){
        for (int i=c[x0].size()-1;i>=0;--i)
            ++cnt[(c[x0][i]-y0+n)%n];
        x0=(x0+x)%n;
        y0=(y0+y)%n;
    }
    int ans=0;
    for (int i=0;i<n;++i)
        if (cnt[ans]<cnt[i])
            ans=i;
    printf("0 %d",ans);
    return 0;
}