// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-06

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 310, mod = 1e9 + 7, inf = 1e9 + 10;

bool a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, k;
	cin >> n >> k;
	int ans = (k % n == 0 ? 0 : 2);
	memset(a, 0, sizeof a);
	int pt = 0, X = 0;
	while(k--){
	    a[pt][(pt + X) % n] = 1;
	    pt = (pt + 1) % n;
	    if(pt == 0)
		X++;
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++)
		cout << a[i][j];
	    cout << "\n";
	}
    }
    return 0;
}