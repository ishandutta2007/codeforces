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

const int maxn = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

int ans[maxn], n;
string s;

void solve(int l, int r, int h = 1){
    bool ok = 1;
    int pos = l;
    vector<pii> v;    
    for(int i = l; i < r; i++){
	if(s[i] == '=')
	    continue;
	if(ok && s[i] == 'R')
	    v.PB({pos, i});
	ok = s[i] == 'L';
	pos = i+1;
    }
    if(ok){
	v.PB({pos, r});
    }
    for(pii p : v){
	assert(p.F <= p.S);
	for(int i = p.F; i <= p.S; i++)
	    ans[i] = h;	
    }
    int bef = l;
    for(pii p : v){
	if(bef < p.F)
	    solve(bef, p.F-1, h+1);
	bef = p.S+1;
    }
    if(bef <= r)
	solve(bef, r, h+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n;
    cin >> s;
    solve(0, n-1);
    for(int i = 0; i < n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}