#include<bits/stdc++.h>
using namespace std;
int od[209],vis[209],A[209],com[209];
vector<int> B[209],v[209];

int ok = 1;
void dfsb(int x){
    vis[x] = 1;
    for(int y : B[x]){
        if(vis[y] && od[x] == od[y]) ok = 0;
        if(!vis[y]){
            od[y] = od[x] ^ 1;
            dfsb(y);
        }
    }
}
int cur;
void dfsv(int x){
    vis[x] = 1;
    com[x] = cur;
    for(int y : v[x]){
        if(y > 0){
            if(vis[y] && A[y] != A[x] - 1) ok = 0;
            if(!vis[y]){
                A[y] = A[x] - 1;
                dfsv(y);
            }
        }
        else{
            y = -y;
             if(vis[y] && A[y] != A[x] + 1) ok = 0;
            if(!vis[y]){
                A[y] = A[x] + 1;
                dfsv(y);
            }
        }
    }
}
int F[209][209];
void addd(int x, int y, int c){
    F[x][y] = min(F[x][y], c);
}
main(){
    int n, m;
    cin >> n >> m;
    for(int i =1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j) F[i][j] = 1e7;

        }
    }
    for(int i = 1; i <= m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        B[a].push_back(b);
        B[b].push_back(a);
        if(c) v[b].push_back(a),
              v[a].push_back(-b);

    }
    dfsb(1);
    if(!ok) {
        cout << "NO"<<endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cur++;
            dfsv(i);
        }
    }
    if(!ok) {
        cout <<"NO"<<endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j : B[i]){
            if(com[i] == com[j] && abs(A[i]-A[j]) != 1){
                cout <<"NO"<<endl;
                return 0;
            }
            if(com[i] != com[j]){
                addd(com[j], com[i], A[j] - A[i] + 1);
            }
        }
    }
    for(int i = 1; i <= cur; i++){
        for(int j = 1; j <= cur; j++){
            for(int k = 1; k <= cur; k++){
                F[j][k] = min(F[j][k], F[j][i] + F[i][k]);
            }
        }
    }
    for(int i = 1; i <= cur; i++){
        if(F[i][i] < 0){
            cout <<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    int mx = 0, st = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(A[j] + F[com[i]][com[j]] - A[i] > mx){
                st = com[i];
                mx = A[j] +F[com[i]][com[j]] - A[i];
            }
        }
    }
    int mn = 0;
    for(int i = 1; i <= n; i++){
        A[i] += F[st][com[i]];
        mn = min(mn, A[i]);
    }
    cout<<mx<<endl;
    for(int i = 1; i <= n; i++)
        cout<<A[i] - mn<<" ";
    cout<<endl;

}