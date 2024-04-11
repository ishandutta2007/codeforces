#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int INF=1e9+7;
int d,s;
queue< pair<int,int> > q;
int dis[502][5002];
pair< int, pair<int,int> > pre[502][5002];
int main(){
    cin>>d>>s;
    for(int i=0;i<=500;i++)for(int j=0;j<=5000;j++)dis[i][j]=-1;
    for(int i=1;i<10;i++){
        q.push(make_pair(i,i)); dis[i][i]=1;
        pre[i][i] = make_pair(i, make_pair(0,0));
    }
    if(s%d==0 && s<=9) {
        printf("%d\n", s); return 0;
    }
    while(q.size()){
        pair<int,int> p=q.front(); q.pop();
        //printf("%d %d %d\n", p.first,p.second,dis[p.first][p.second]);
        for(int i=0;i<10;i++){
            int x=(10*p.first+i)%d;
            int y=(p.second+i);
            //printf("x=%d,y=%d\n", x,y);
            if(y<=s && dis[x][y]==-1){
                dis[x][y] = dis[p.first][p.second] + 1;
                q.push(make_pair(x,y)); pre[x][y] = make_pair(i,p); 
            }
        }
    }
    //printf("dis = %d\n", dis[0][s]);
    if(dis[0][s]==-1) {
        printf("-1\n"); return 0;
    }
    vector<int> ans;
    pair<int,int> now = make_pair(0,s);
    while(true) {
        //printf("%d", pre[now.first][now.second].first);
        ans.push_back(pre[now.first][now.second].first);
        now = pre[now.first][now.second].second;
        if(now.second == 0) break;
    }
    for(int i=ans.size()-1;i>=0;i--) printf("%d", ans[i]);
}