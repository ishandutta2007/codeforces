#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll L = 0x7fffffffffffffff, M = 1;
ll N, sum, v[100005], a, b;
vector<ll> adj[100005];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){ return (a * b) / gcd(a, b); }

void calc(int n = 0, int p = 0, ll d = 1LL){
    M = lcm(M, d);
    
    if(d>sum || d<0){
        cout << sum << endl;
        exit(0); 
    }
    
    if(adj[n].size()==1 && n>0)
        L = min(L, d*v[n]);

    for(int i=0; i<adj[n].size(); i++)
        if(adj[n][i] != p)
            calc(adj[n][i], n, d*(adj[n].size()-!!n));
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        sum += v[i];
    }

    for(int i=1; i<N; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    calc();
    cout << sum-L/M*M << endl;
    return 0;
}