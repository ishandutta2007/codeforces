#include <iostream>
#include <set>
using namespace std;
const int N=1005;
char s[N][N]; int n,m;
int par[2000000+10],sz[2000000+10];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int id(int r,int c){
    if(r<1||r>n||c<1||c>m||s[r][c]=='*')return 0;
    return r*m + c;
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    for(int i=0;i<2000000;i++)par[i]=i,sz[i]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*')continue;
            for(int d=0;d<4;d++){
                int ni=i+dx[d];
                int nj=j+dy[d];
                int u=id(i,j);
                int v=id(ni,nj); if(v==0||find(u)==find(v))continue;
                sz[find(v)] += sz[find(u)];
                par[find(u)]=find(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='.'){
                printf(".");continue;
            }
            set<int> st;
            for(int d=0;d<4;d++){
                int v=id(i+dx[d],j+dy[d]); if(v==0)continue;
                //if(i==1&&j==1)printf("v=%d, %d %d\n", v,i+dx[d],j+dy[d]);
                st.insert(find(v));
            }
            int ans=1;
            for(auto x:st) ans+=sz[find(x)];
            printf("%d", ans%10);
        }
        printf("\n");
    }
}