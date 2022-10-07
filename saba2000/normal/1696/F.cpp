#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> f[10009];
int e[109][109][109];
int dist[109][109];
int no[109][109];
int A[100009];
int B[100009];
int vis[100009];
vector<int> v;
void dfs(int x){
    vis[x] = 1;
    v.push_back(x);
    for(int y : f[x])
        if(!vis[y]) dfs(y);
}
void solve(){

    ll n;
    cin >> n;
    int M = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1;j < n; j++)
            no[i][j] = ++M,
            no[j][i] = M,
            A[M] = i,
            B[M] = j;
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                e[i][j][k] = 0;
    for(int i = 1; i <= M; i++)
        vis[i] = 0,
        f[i].clear();
    for(int i = 0; i < n; i++){
        for(int j  = i +1; j < n; j++){
            string s;
            cin >> s;
            int ok = 0;
            for(int k = 0; k < n; k++){
                if(s[k] == '1'){
                    f[no[i][k]].push_back(no[j][k]);
                    f[no[j][k]].push_back(no[i][k]);
                    ok = 1;
                    e[i][j][k] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= M; i++){
        if(!vis[i]) {
            v.clear();
            dfs(i);
            int bad = 0;
            if(v.size() == n-1){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(i == j) dist[i][j] = 0;
                        else dist[i][j] = n + 1;
                    }
                }
                for(int i = 0; i < n-1; i++){
                    dist[A[v[i]]][B[v[i]]] = 1;
                    dist[B[v[i]]][A[v[i]]] = 1;
                }

                for(int k = 0; k < n; k++)
                    for(int i = 0; i < n; i++)
                        for(int j = 0; j < n; j++)
                                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        if(dist[i][j] > n) bad = 1;
                 for(int i = 0; i < n; i++)
                    for(int j = i+1; j < n; j++)
                        for(int k = 0; k < n; k++)
                            if((dist[i][k] == dist[j][k]) != e[i][j][k]){
                                bad = 1;
                            }
                if(bad){
                    continue;
                }
                cout<<"Yes"<<endl;
                for(int i =0; i < n-1; i++)
                    cout<<A[v[i]]+1<<" "<<B[v[i]]+1<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;

}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
/*
4
0010 0000 0000
0000 0000
0100

*/