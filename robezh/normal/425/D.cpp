#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n, a, b;
int x[N], y[N];
vector<int> vx[N], vy[N];
unordered_set<int> sx[N], sy[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x[i], &y[i]);
        vx[y[i]].push_back(x[i]);
        vy[x[i]].push_back(y[i]);
        sx[y[i]].insert(x[i]);
        sy[x[i]].insert(y[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vx[y[i]].size() > vy[x[i]].size()){
            for(auto ny : vy[x[i]]){
                if(ny < y[i] && sx[y[i]].count(x[i] - (y[i] - ny)) && sx[ny].count(x[i] - (y[i] - ny))) ans++;
            }
        }
        else{
            for(auto nx : vx[y[i]]){
                if(nx < x[i] && sy[x[i]].count(y[i] - (x[i] - nx)) && sy[nx].count(y[i] - (x[i] - nx))) ans++;
            }
        }
    }
    cout << ans;
}