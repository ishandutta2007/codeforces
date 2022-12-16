// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 110, mod = 1e9 + 7;
const ll inf = 1e18;

map<string, int> mp;

void ask(int l, int r, int x){
    if(l>r)
	return;
    cout<<"? "<<l<<" "<<r<<endl;
    for(int R = l; R<=r; R++){
	for(int L = R; L>=l; L--){
	    string s; cin>>s;
	    sort(s.begin(), s.end());
	    mp[s]+=x;
	    assert(s.empty() == 0);
	}
    }
}

int cnt[maxn][26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    ask(1, n, 1);
    ask(2, n, -1);
    cout<<"! ";
    int CNT = 0;
    for(auto it : mp){
	if(it.S != 0){
	    assert(it.S == 1);
	    CNT++;
	    for(char ch : it.F)
		cnt[sz(it.F)][ch - 'a']++;
	}
    }
    assert(CNT == n);
    for(int i = 1; i<= n; i++){
	int c = -1;
	for(int j = 0; j < 26; j++){
	    if(cnt[i][j] != cnt[i-1][j])
		assert(cnt[i][j] - 1 == cnt[i-1][j]), assert(c==-1), c = j;
	}
	assert(c != -1);
	cout<<char('a'+c);
    }
    return cout<<endl,0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")