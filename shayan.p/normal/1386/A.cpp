// And you curse yourself for things you never done

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

bool ask(ll x){
    cout << "? " << x+1 << endl;
    bool ans;
    cin >> ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	ll n;
	cin >> n;
	ll l = 0, r = n, pos = 0;
	bool o = 0;
	ll ln = 0;
	while(r-l > 1){
	    ll mid = (l+r) >> 1;
	    if(o)
		pos+= mid - ln;
	    ln = mid;
	    l = mid;
	    o^=1;
	}
	
	l = 0, r = n, o = 0;
	ask(pos);
	while(r-l > 1){
	    ll mid = (l+r) >> 1;
	    bool chk = 0;
	    if(o)
		chk = ask(pos - mid), pos-= mid;
	    else
		chk = ask(pos + mid), pos+= mid;
	    o^=1;
	    if(chk)
		r = mid;
	    else
		l = mid;		    
	}
	cout << "= " << r << endl;	
    }
    return 0;
}