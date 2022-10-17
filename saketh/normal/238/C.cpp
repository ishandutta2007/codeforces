#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 3030;

int N;
vector<int> adj[MAXN];
int a[MAXN], b[MAXN];

int up[MAXN];

void dpup(int loc, int par = -1){
    for(int e : adj[loc]){
        int nbr = a[e] + b[e] - loc;
        if(nbr == par) continue;
        dpup(nbr, loc);
        up[loc] += up[nbr];
        if(b[e] == loc) up[loc]++; 
    }
}

int rz[MAXN];

void dprz(int loc, int par = -1, int away = 0, int meet = 0, int come = 0){
    //cout << loc << " " << par << " " << away << " " << meet << " " << come << endl;
    rz[loc] = up[loc] + away + meet;
    
    for(int e : adj[loc]){
        int nbr = a[e] + b[e] - loc;
        if(nbr == par) continue;
        dprz(nbr, loc, 
            away + up[loc] - up[nbr] - (b[e] == loc),
            min(meet + (a[e] == loc), come + (b[e] == loc)),
            come + (b[e] == loc));
    }
}

int solve(int root){
    memset(up, 0, sizeof(up));
    dpup(root);
    memset(rz, 0, sizeof(rz));
    dprz(root);
    int ans = MAXN;
    for(int i=0; i<N; i++){
        ans = min(ans, rz[i]);
    }
    return ans;    
}


int main(){
    setup();
    cin >> N;
    for(int i=0; i<N-1; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        adj[a[i]].push_back(i);
        adj[b[i]].push_back(i);
    }

    int ans = MAXN;
    for(int i=0; i<N; i++){
        ans = min(ans, solve(i));
    }
    cout << ans << endl;
}