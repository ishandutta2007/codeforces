#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<pii> adj[MAX_N] , ed;
vector<int> v , c;
set<int> s;
int dead = -1;
bool mark[MAX_N] , ret = false;

void DFS(int r , int par , int yal){
    mark[r] = true;
    s.insert(r);
    v.push_back(yal);
    for(auto p : adj[r]){
        int i = p.first , j = p.second;
        if(j == dead) continue;
        if(s.count(i)){
            if(~dead){
                ret = true;
                return;
            }
            int t = r , vs = v.size();
            for(int q = vs - 1 ; q >= 0 && t != i ; q--){
                c.push_back(v[q]);
                t = ed[v[q]].first;
            }
            c.push_back(j);
            ret = true;
            return;
        }
        if(mark[i] || i == par) continue;
        DFS(i , r , j);
        if(ret) return;
    }
    s.erase(r);
    v.pop_back();
    return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    int n , m;
    cin>>n>>m;
    memset(mark , 0 , sizeof(mark));
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin>>v>>u; v--; u--;
        adj[v].push_back({u , i});
        ed.push_back({v , u});
    }
    for(int i = 0 ; i < n && !ret ; i++){
        if(!mark[i]){
            DFS(i , -1 , -1);
        }
    }
    if(!ret){
        cout<<"YES\n";
        return 0;
    }
    for(auto o : c){
        s.clear();
        v.clear();
        memset(mark , 0 , sizeof(mark));
        ret = false;
        dead = o;
        for(int i = 0 ; i < n ; i++){
            if(!mark[i]){
                DFS(i , -1 , -1);
            }
        }
        if(!ret){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
	return 0;
}

/*
4 6
1 2 2 3 3 4 4 1
2 4 4 2
*/