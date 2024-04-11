#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9+7;
const int N = 2000+10;
int n,k;
char s[N][N];
int dp[N][N],vis[N][N];
pair<int,int> pre[N][N];
bool in(int x,int y){
    return x<=n && y<=n && vis[x][y]==0;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%s",s[i]+1);
    }
    for(int i=0;i<N;i++) dp[0][i]=dp[i][0]=INF;
    dp[1][1] = s[1][1]=='a'?0:1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1)continue;
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (s[i][j]=='a'?0:1);
        }
    }

    int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]<=k) {
                mx=max(mx,i+j);
            }
        }
    }
    //printf("mx=%d\n", mx);
    queue< pair<int,int> > q; vector< pair<int,int> > vec;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]<=k && i+j==mx) {
                //printf("# %d %d\n", i, j);
                q.push(make_pair(i,j)); vis[i][j]=1;
            }
        }
    }

    vector<char> ans;
    if (mx==0) {
        ans.push_back(s[1][1]); q.push(make_pair(1,1));
    }
    while(q.size()) {
        int mn = 'z'+1; vec.clear();
        while(q.size()) {
            pair<int,int> u = q.front(); q.pop();
            int x=u.first, y=u.second;
            if(in(x+1, y)) mn = min(mn, (int)s[x+1][y]);
            if(in(x, y+1)) mn = min(mn, (int)s[x][y+1]);
            vec.push_back(u);
        }
        //printf("! %c\n", mn);
        ans.push_back(mn);
        for(auto u: vec) {
            int x=u.first, y=u.second;
            if(in(x+1, y) && s[x+1][y]==mn) {
                pre[x+1][y] = u;
                q.push(make_pair(x+1,y)); vis[x+1][y]=1;
            }
            if(in(x, y+1) && s[x][y+1]==mn) {
                pre[x][y+1] = u;
                q.push(make_pair(x,y+1)); vis[x][y+1]=1;
            }
        }
    }



    int cntA = mx-1;
    for(int i=1;i<=cntA;i++) printf("a");
    for(int i=0;i<(int)ans.size()-1;i++)printf("%c", ans[i]); printf("\n");

}

/*
5 0
bwwwz
hrhdh
sepsp
sqfaf
ajbvw
*/