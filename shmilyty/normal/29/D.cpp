#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
#define INF (1<<29)
 
int n;
int dist[310][310];
vector <int> v;
vector <int> ans;
 
int func(int cur, int goal){
    int i;
    
    while(cur != goal){
        REP(i,n) if(dist[cur][i] == 1 && dist[i][goal] < dist[cur][goal]) break;
        cur = i;
        ans.push_back(cur+1);
    }
}
 
int main(void){
    int i,j,k,a,b,tmp;
    
    cin >> n;
    REP(i,n) REP(j,n) dist[i][j] = ((i == j) ? 0 : INF);
    REP(i,n-1){
        cin >> a >> b; a--; b--;
        dist[a][b] = dist[b][a] = 1;
    }
    REP(k,n) REP(i,n) REP(j,n) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    
    v.push_back(0);
    while(cin >> tmp) v.push_back(tmp-1);
    v.push_back(0);
    
    REP(i,v.size()-1) func(v[i],v[i+1]);
    
    if(ans.size() != 2*(n-1)){
        cout << -1 << endl;
    } else {
        printf("1");
        REP(i,ans.size()) printf(" %d",ans[i]);
        printf("\n");
    }
    
    return 0;
}