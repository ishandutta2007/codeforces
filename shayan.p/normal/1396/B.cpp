// Oh damn! Suddenly you're free to fly
// Shayan.P  2020-08-30

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	int mx = 0, sm = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
	    int x;
	    cin >> x;
	    sm+= x;
	    mx = max(mx, x);
	}
	cout << ((2 * mx <= sm && (sm % 2 == 0)) ? "HL\n" : "T\n");		
    }
    return 0;
}