// And you curse yourself for things you never done
// Shayan.P  2020-08-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 30, mod = 1e9 + 7, inf = 1e9 + 10;

ll a[maxn][maxn];
ll C[2 * maxn][2 * maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < 2 * maxn; i++){
	C[i][0] = C[i][i] = 1;
	for(int j = 1; j < i; j++)
	    C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    
    int n;
    cin >> n;
    for(int i = n-2; i >= 0; i--){
	for(int j = 1; j < n; j++){
	    ll sm1 = 0, sm2 = 0;
	    for(int k = i+1; k < n; k++)
		sm1+= a[k][j];	    
	    for(int k = j-1; k < n; k++)
		sm2+= a[i+1][k];
	    for(int k = i+2; k < n; k++)
		sm2+= a[k][n-1];
	    a[i][j] = sm2 + 1 - sm1;
	    assert(a[i][j] >= 0);
	}
    }
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++)
	    cout << a[i][j] << " ";
	cout << endl;
    }
    int q;
    cin >> q;
    while(q--){
	ll w;
	cin >> w;
	int posx = 0, posy = 0;
	vector<pii> ans;
	ans.PB({0, 0});
	for(int i = 0; i < 2*n-2; i++){
	    if(posx == n-1)
		posy++;
	    else if(posy == n-1)
		posx++;
	    else{
		int rx = n-1 - posx - 1, ry = n-1 - posy;
		if(w >= C[rx + ry][rx]){
		    w-= C[rx + ry][rx];
		    posy++;
		}
		else{
		    posx++;
		}		    
	    }
	    ans.PB({posx, posy});
	}
	for(pii p : ans){
	    cout << p.F+1 << " " << p.S+1 << endl;
	}
    }
    return 0;
}