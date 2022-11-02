#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N, M, K;
pair<int, pii> edges[MAX_N];
int dsu[MAX_N];
int sz[MAX_N];
int numSpec[MAX_N];
int find(int i){
    if(dsu[i] == i) return i;
    dsu[i] = find(dsu[i]);
    //cout << i << " " << dsu[i] << "\n";
    return dsu[i];
}
int unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y) return -1;
    
    //cout << "combining " << x << " " << y << "\n";
    
    if(sz[x] < sz[y]) swap(x, y);
    
    sz[x] += sz[y];
    numSpec[x] += numSpec[y];
    dsu[y] = x;

    return numSpec[x];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    F0R(_, K){
        int x;
        cin >> x;
        numSpec[x] = 1;
    }
    
    F0R(i, M){
        cin >> edges[i].s.f >> edges[i].s.s >> edges[i].f;
    }
    
    sort(edges, edges+M);
    
    FOR(i, 1, N){
        dsu[i] = i;
        sz[i] = 1;
    }
    
    F0R(i, M){
        if(unite(edges[i].s.f, edges[i].s.s) == K){
            //cout << edges[i].f << "\n";
            F0R(_, K){
                cout << edges[i].f << " ";
            }
            return 0;
        }
    }
    
    return 0;
}