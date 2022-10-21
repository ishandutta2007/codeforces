#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500;

int n, cnt = 0;
int num[N];
bool vis[N];

int dfs(int v){
    vis[v] = true;
    if(!vis[num[v]]) return dfs(num[v]) + 1;
    else return 1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt += dfs(i)-1;
        }
    }
    if(cnt % 2 == n % 2) cout << "Petr";
    else cout << "Um_nik";
}