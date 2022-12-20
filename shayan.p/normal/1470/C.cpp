#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int n, k;

int nxt(int x){
    return (x + 1) % n;
}
int prv(int x){
    return (x + n-1) % n;
}
int ask(int pos){
    cout << "? " << pos + 1 << endl;
    int x;
    cin >> x;
    return x;
}
void tell(int x){
    cout << "! " << x+1 << endl;
    exit(0);
}
void check(int pos){
    if(ask(pos) != k)
	return;
    if(ask(prv(pos)) < k && k < ask(nxt(pos)))
	tell(pos);
}
void solve(){
    int pt = 0, x = 0, len = 0;
    while(ask(x) == k){
	if(len >= n){
	    pt = 0, x = 0;
	    while(true){
		check(x);
		x = (x + 2*pt) %n;
		pt++;
	    }
	}
	len+= 2*pt;
	x = (x + 2*pt) % n;	
	pt++;
    }
    int l = (x - pt + n) % n, r = (x + pt + n) % n;
    int st = x;
    while(st != (r+1)%n){
	if(ask(st) == k)
	    check(st);
	st = (st + 1) % n;
    }
    st = x;
    while(st != (l+n-1)%n){
	if(ask(st) == k)
	    check(st);
	st = (st + n-1) %n;
    }
    assert(0);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    cin >> n >> k;
    solve();
    return 0;
}