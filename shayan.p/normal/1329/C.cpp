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

const int maxn = 3e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn], h, g;
vector<int> vec;
vector<int> sol;

void dn(int pos){
    vec.PB(pos);
    if(a[2*pos] == 0 && a[2*pos+1] == 0)
	return;
    if(a[2*pos] > a[2*pos+1])
	dn(2*pos);
    else
	dn(2*pos+1);
}
void solve(int pos){
    if(pos >= (1<<g))
	return;
    while(true){
	vec.clear();
	dn(pos);
	if(vec.back() < (1<<g)){
	    solve(2*pos);
	    solve(2*pos+1);
	    return;
	}
	sol.PB(pos);
	for(int i = 0; i < sz(vec)-1; i++)
	    a[vec[i]] = a[vec[i+1]];
	a[vec.back()] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	cin >> h >> g;
	sol.clear();
	for(int i = 1; i < (1<<h); i++)
	    cin >> a[i];
	for(int i = (1<<h); i < (1<<(h+1)); i++)
	    a[i] = 0;
	solve(1);
	ll ans = 0;
	for(int i = 1; i < (1<<g); i++)
	    ans+= a[i];
	cout << ans << "\n";
	for(int x : sol)
	    cout << x << " ";
	cout << "\n";
    }
    return 0;
}