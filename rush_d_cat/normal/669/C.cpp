#include<iostream>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
pair<int,int> a[100+2][100+2],z;
int map[105][105];
int n,m,q;
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=make_pair(i,j);
            map[i][j]=0;
        }
    }
    for(int i=1;i<=q;i++){
        int tmp,x;cin>>tmp>>x;
        if(tmp==1){
            z = a[x][1];
            for(int j=0;j<m;j++){
                a[x][j]=a[x][j+1];
            }
            a[x][m]=z;
        }
        if(tmp==2){
            z = a[1][x];
            for(int j=0;j<n;j++){
                a[j][x]=a[j+1][x];
            }
            a[n][x]=z;
        }
        if(tmp==3){
            int y,v;cin>>y>>v;
           // printf("%d %d\n",a[x][y].first,a[x][y].second);
            map[a[x][y].first][a[x][y].second]=v;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j!=m) printf("%d ",map[i][j]);
            else printf("%d\n",map[i][j]);
        }
    }
    return 0;
}