#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
#define mp make_pair
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
bool used[11][11][11];
char a[11][11][11];
void solve(){
    int n,m,k,x,y;
    cin>>k>>n>>m;
    for(int i=0;i<k;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    cin>>x>>y;
    int ans=0;
    queue<pair<pi,int> > q;
    q.push(mp(pi(0,x-1),y-1));
    used[0][x-1][y-1]=1;
    while(!q.empty()){
        ++ans;
        pair<pi,int> cur=q.front();
        q.pop();
        if(cur.first.first>0 && a[cur.first.first-1][cur.first.second][cur.second]=='.' && !used[cur.first.first-1][cur.first.second][cur.second]){
            used[cur.first.first-1][cur.first.second][cur.second]=true;
            q.push(mp(pi(cur.first.first-1,cur.first.second),cur.second));
        }
        if(cur.first.first<k-1 && a[cur.first.first+1][cur.first.second][cur.second]=='.' && !used[cur.first.first+1][cur.first.second][cur.second]){
            used[cur.first.first+1][cur.first.second][cur.second]=true;
            q.push(mp(pi(cur.first.first+1,cur.first.second),cur.second));
        }
        if(cur.first.second>0 && a[cur.first.first][cur.first.second-1][cur.second]=='.' && !used[cur.first.first][cur.first.second-1][cur.second]){
            used[cur.first.first][cur.first.second-1][cur.second]=true;
            q.push(mp(pi(cur.first.first,cur.first.second-1),cur.second));
        }
        if(cur.first.second<n-1 && a[cur.first.first][cur.first.second+1][cur.second]=='.' && !used[cur.first.first][cur.first.second+1][cur.second]){
            used[cur.first.first][cur.first.second+1][cur.second]=true;
            q.push(mp(pi(cur.first.first,cur.first.second+1),cur.second));
        }
        if(cur.second>0 && a[cur.first.first][cur.first.second][cur.second-1]=='.' && !used[cur.first.first][cur.first.second][cur.second-1]){
            used[cur.first.first][cur.first.second][cur.second-1]=true;
            q.push(mp(pi(cur.first.first,cur.first.second),cur.second-1));
        }
        if(cur.second<m-1 && a[cur.first.first][cur.first.second][cur.second+1]=='.' && !used[cur.first.first][cur.first.second][cur.second+1]){
            used[cur.first.first][cur.first.second][cur.second+1]=true;
            q.push(mp(pi(cur.first.first,cur.first.second),cur.second+1));
        }
    }
    cout<<ans;
}