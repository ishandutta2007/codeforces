#include <iostream>
#include <vector>
using namespace std;
int n,m;
int a[52][52],b[52][52];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    vector< pair<int,int> > ans;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1] == 4){ 
                b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
                ans.push_back(make_pair(i,j));
            }
        }
    }
    bool ok=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!=b[i][j])ok=0;
    if(!ok) printf("-1\n");
    else {
        printf("%d\n", ans.size());
        for(auto p: ans)
            printf("%d %d\n", p.first,p.second);
    }
}