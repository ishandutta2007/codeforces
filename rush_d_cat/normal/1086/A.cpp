#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;

const LL MOD = 1e9+7;
const int N=1000+10;

int x[3],y[3],vis[N][N];
vector< pair<int,int> > vec;

void solve(int px,int py){
    int miny = min(min(y[0],y[1]),y[2]);
    int maxy = max(max(y[0],y[1]),y[2]);
    for(int i=miny;i<=maxy;i++) vis[px][i]=1;
    for(int i=0;i<3;i++){
        if(x[i]>=px) {
            int p=x[i];
            while(vis[p][y[i]] == 0) {
                vis[p][y[i]]=1; --p; 
            }
        } else {
            int p=x[i];
            while(vis[p][y[i]] == 0) {
                vis[p][y[i]]=1; ++p;
            }
        }
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(vis[i][j])vec.push_back(make_pair(i,j));
}

int main(){
    for(int i=0;i<3;i++)cin>>x[i]>>y[i];

    int mn=1e9; int px,py;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            int sum=0;
            for(int k=0;k<3;k++)sum+=abs(i-x[k])+abs(j-y[k]);
            if(sum<mn){
                mn=sum; px=i,py=j;
            }
        }
    }

    solve(px,py);
    printf("%d\n", vec.size());
    for(auto p:vec) printf("%d %d\n", p.first,p.second);
}