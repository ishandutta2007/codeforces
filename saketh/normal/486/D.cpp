#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int D, N, v[2048];
vector<int> adj[2048];

long long ways[2048][2048][3];

void calc(int loc, int par = -1){
    for(int L=0; L<=2000; L++)
        if(L <= v[loc] && v[loc] <= (L+D)){    
            ways[loc][L][1] = 1;
            ways[loc][L][2] = 1;
        }

    for(int i=0; i<adj[loc].size(); i++){
        int nbr = adj[loc][i];
        
        if(nbr == par) continue;
        calc(nbr, loc);

        for(int L = 0; L <= 2000; L++){
            ways[loc][L][0] = (ways[loc][L][0] + ways[nbr][L][0]) % MOD;
            ways[loc][L][0] = (ways[loc][L][0] + ways[nbr][L][1]) % MOD;
            if(L <= v[loc] && v[loc] <= (L+D)){
                    ways[loc][L][1] = (ways[loc][L][1] * (1 + ways[nbr][L][1] + ways[nbr][L][2])) % MOD;
                    ways[loc][L][2] = (ways[loc][L][2] * (1 + ways[nbr][L][2])) % MOD;
            }
        }
    }

    for(int L=0; L<=2000; L++)
        if(L <= v[loc] && v[loc] <= (L+D)){
            if(L == v[loc]) ways[loc][L][2] = 0;
            else ways[loc][L][1] = (ways[loc][L][1] + MOD - ways[loc][L][2]) % MOD;  
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> D >> N;

    for(int i=0; i<N; i++)
        cin >> v[i];

    for(int i=1; i<N; i++){
        int a, b;
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    calc(0);
    
    int ans = 0;
    for(int L = 0; L <= 2000; L++){
        ans = (ans + ways[0][L][0]) % MOD;
        ans = (ans + ways[0][L][1]) % MOD;
    }

    cout << ans << endl;
    return 0;
}