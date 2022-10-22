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

const ll MAX_N = 7e4 + 20 , md = 1e9 + 7;
 
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

vector<pii> p;
vector<int> a;
int par[MAX_N] , cn[MAX_N] , ch[MAX_N] , pos[MAX_N] , rps[MAX_N];
bool mark[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    bitset<MAX_N> dp;
    dp[0] = 1;
    int n , s;
    cin>>n>>s;
    fill(ch , ch + n , -1);
    memset(cn , 0 , sizeof(cn));
    memset(mark , 0 , sizeof(mark));
    for(int i = 0 ; i < n ; i++){
        int h;
        cin>>h;
        p.push_back({h , i});
    }
    sort(p.begin() , p.end());
    for(int i = 0 ; i < n ; i++){
        a.push_back(p[i].first);
        pos[p[i].second] = i;
        rps[i] = p[i].second;
    };
    if(a[n - 1] > s){
        cout<<"-1\n";
        return 0;
    }
    for(int i = 0 ; i < n - 1 ; i++){
        bitset<MAX_N> h = dp;
        dp |= (dp << a[i]);
        h ^= dp;
        for(int j = h._Find_first() ; j < MAX_N ; j = h._Find_next(j)){
            par[j] = i;
        }
    }
    if(dp[s - a[n - 1]] == 0){
        cout<<"-1\n";
        return 0;
    }
    int x = s - a[n - 1];
    while(x > 0){
        mark[par[x]] = true;
        cn[par[x]] = a[par[x]];
        x -= a[par[x]];
    }
    int ls = n - 1;
    for(int i = n - 2 ; i >= 0 ; i--){
        if(mark[i]) continue;
        ch[ls] = i;
        cn[ls] = a[ls] - a[i];
        ls = i;
    }
    cn[ls] = a[ls];
    for(int i = 0 ; i < n ; i++){
        cout<<cn[pos[i]]<<' ';
        if(ch[pos[i]] == -1){
            cout<<"0\n";
            continue;
        }
        cout<<"1 "<<rps[ch[pos[i]]] + 1<<'\n';
    }
	return 0;
}