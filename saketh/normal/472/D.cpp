#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

int N; long long d[2005][2005];
int used[2005];
vector<pair<int, long long> > adj[2005];
bool verif[2005][2005];

bool good(int loc, int par=-1, int pard = 0){
    used[loc] = 1;
    if(par != -1) adj[loc].push_back(make_pair(par, pard));

    priority_queue<pair<int, int> > cc;
    for(int i=0; i<N; i++)
        if(used[i]) continue;
        else cc.push(make_pair(-1 * d[loc][i], i));

    while(true){
        while(!cc.empty() && used[cc.top().second]) cc.pop();
        if(cc.empty()) return true;

        long long ew = -1 * cc.top().first;
        int ei = cc.top().second;

        for(int i=0; i<N; i++){
            if(used[i]) continue;
            if(d[loc][i] < d[ei][i]) used[i] = (69 + loc);
        }

        if(!good(ei, loc, d[loc][ei])) return false;
        adj[loc].push_back(make_pair(ei, d[loc][ei]));

        for(int i=0; i<N; i++)
            if(used[i] == (69 + loc))
                used[i] = 0;
    }
}

void dfs(int loc, int root, int par=-1, long long curd=0){
    verif[root][loc] = curd == d[root][loc];

    for(int i=0; i<adj[loc].size(); i++)
        if(adj[loc][i].first == par) continue;
        else dfs(adj[loc][i].first, root, loc, curd + adj[loc][i].second);
}

bool check_dist(){
    for(int i=0; i<N; i++)
        dfs(i, i);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(!verif[i][j]) 
                return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    bool sanit = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> d[i][j];
            
            if((i==j && d[i][j]!=0) || (i!=j && d[i][j]==0)){
                sanit = false;
            }
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(d[i][j] != d[j][i])
                sanit = false;

    if(sanit && good(0) && check_dist()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}