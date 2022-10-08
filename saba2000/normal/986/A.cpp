#include<bits/stdc++.h>
using namespace std;
vector<int> V[1009],v[100009], ans[100009];
int f[100009],d[100009],a[100009];
main(){
    int n,m,k,s;
    cin >> n>>m>>k>>s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        V[a[i]].push_back(i);
    }
    for(int i= 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= k; i++){
        queue<int> q;
        for(int i = 1; i <= n; i++)
            d[i] = 0,f[i] = 0;
        for(int j = 0; j <V[i].size(); j++)
        q.push(V[i][j]), f[V[i][j]] = 1;
        while(q.size()){
            int x = q.front();
            q.pop();
            for(int i = 0; i < v[x].size(); i++){
                if(f[v[x][i]] == 0){
                    f[v[x][i]] = 1;
                    d[v[x][i]] = d[x] + 1;
                    q.push(v[x][i]);
                }
            }
        }
        for(int i = 1; i <= n; i++)
            ans[i].push_back(d[i]);
    }
    for(int i = 1; i <= n; i++){
        sort(ans[i].begin(),ans[i].end());
        int A = 0;
        for(int j =0 ; j < s; j++)
            A += ans[i][j];
        printf("%d ", A);
    }
    cout<<endl;

}