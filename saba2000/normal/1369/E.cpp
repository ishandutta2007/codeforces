#include<bits/stdc++.h>
#define ll long long
using namespace std;
int w[200009];
vector<int> v[200009];
int f[200009],N[200009];
int x[200009],y[200009];
main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    queue<int> q;
    for(int i = 1; i <= m; i++){
        cin >> x[i] >> y[i];
        v[x[i]].push_back(i);
        v[y[i]].push_back(i);
        N[x[i]]++;
        N[y[i]]++;

    }
    for(int i = 1; i <= n; i++){
        if(w[i] >= N[i]) q.push(i);
    }
    vector<int> pas;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int z : v[u]){
            if(f[z]) continue;
            f[z] = 1;
            pas.push_back(z);
            if(x[z] == u) {
                N[y[z]]--;
                if(w[y[z]] == N[y[z]]) q.push(y[z]);
            }
            else{
                N[x[z]]--;
                if(w[x[z]] == N[x[z]]) q.push(x[z]);
            }
        }
    }
    if(pas.size() == m){
    cout << "ALIVE"<<endl;
    reverse(pas.begin(),pas.end());
    for(int x : pas)
        cout<<x<<" ";
    cout<<endl;
    }
    else cout<<"DEAD"<<endl;


}