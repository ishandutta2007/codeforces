#include<bits/stdc++.h>
using namespace std;
int f[100009];
unordered_map<int,int> v[100009];
set<int> s;
void bfs(int x){
    queue<int>q;
    q.push(x);
    s.erase(s.find(x));
    f[x] = 1;
    while(q.size()){
        int x = q.front();
        q.pop();
        vector<int> V;
        for(auto y = s.begin(); y != s.end(); y++){
            int u = *y;
            if(v[x][u]) continue;
            V.push_back(u);
        }
        for(int y : V)
            q.push(y),
            f[y] = 1,
            s.erase(s.find(y));
    }
}
main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    for(int i =1 ;i <= n; i++)
        s.insert(i);
    int ans = 0;
    for(int i =1 ;i <= n; i++){
        if(f[i] == 0){
            ans++;
            bfs(i);
        }
    }
    cout<<ans-1<<endl;
}
//1=3=5=2