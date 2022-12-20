// And you curse yourself for things you never done
// Shayan.P  2020-07-29

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int L[maxn];
set<pii> pq[2];
set<int> del;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;    
    cin >> n;
    int ans = n;
    vector<pair<int, pair<pii, int> > > vec;
    for(int i = 1; i <= n; i++){
	int a, b, c;
	cin >> a >> b >> c;
	--c;
	vec.PB({a, { {0, c}, i }});
	vec.PB({b, { {1, c}, i }});
	L[i] = a;
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(auto it : vec){
	if(del.count(it.S.S))
	    continue;
	int c = it.S.F.S;
	if(it.S.F.F == 0){
	    if(!pq[1-c].empty()){
		ans--;
		del.insert(pq[1-c].rbegin()->S);
		pq[1-c].erase(*pq[1-c].rbegin());
	    }
	    pq[c].erase({it.F, it.S.S});
	}
	else{
	    pq[c].insert({L[it.S.S], it.S.S});
	}
    }
    return cout << ans << endl, 0;
}