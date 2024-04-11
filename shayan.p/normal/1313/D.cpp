// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

map<int, vector<int> > mp;
int dp[1<<8], n, m, k, MSK;
int pos[maxn];

void add(int u){
    MSK^= 1<<u;
}
void era(int u){
    MSK^= 1<<u;
    for(int msk = 0; msk < (1<<k); msk++)
	if(bit(msk, u))
	    dp[msk] = dp[msk ^ (1<<u)] = max(dp[msk], dp[msk ^ (1<<u)]);
}
void upd(int ds){
    for(int msk = 0; msk < (1<<k); msk++){
	if(__builtin_popcount(MSK & msk) & 1)
	    dp[msk]+= ds;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
	int a, b;
	cin >> a >> b;
	mp[a].PB(i);
	mp[++b].PB(-i);
    }
    int lst = 0;
    for(auto it : mp){
	upd(it.F - lst);
	lst = it.F;
	for(auto x : it.S){
	    if(x < 0){
		era(pos[-x]);
	    }
	}
	for(auto x : it.S){
	    if(x > 0){
		int emp = 0;
		while(bit(MSK, emp))
		    emp++;
		pos[x] = emp;
		add(pos[x]);
	    }
	}
    }
    return cout << dp[0] << endl, 0;
}