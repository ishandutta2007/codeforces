// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-24

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

int a[maxn];

int solve(){
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	x^= a[i];
    }
    if(x == 0)
	return 0;
    int id = 31 - __builtin_clz(x);
    int A = 0, B = 0;
    for(int i = 0; i < n; i++){
	if(bit(a[i], id))
	    A++;
	else
	    B++;
    }
    if(A % 4 == 1)
	return 1;
    return (B & 1 ? 1 : -1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int x = solve();
	if(x == -1)
	    cout << "LOSE\n";
	if(x == 0)
	    cout << "DRAW\n";
	if(x == 1)
	    cout << "WIN\n";
    }
    return 0;
}