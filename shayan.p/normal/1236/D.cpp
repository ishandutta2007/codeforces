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

vector<int> vx[maxn], vy[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
	int a, b;
	cin >> a >> b;
	--a, --b;
	vx[a].PB(b);
	vy[b].PB(a);
    }
    for(int i = 0; i < maxn; i++){
	vx[i].PB(-1), vx[i].PB(m);
	vy[i].PB(-1), vy[i].PB(n);
	sort(vx[i].begin(), vx[i].end());
	sort(vy[i].begin(), vy[i].end());
    }
    int dir = 0;
    ll ans = 1;
    int x = 0, y = 0;
    int xl = -inf, yl = -inf, xr = inf, yr = inf;
    bool frst = 0;
    
    while(true){
	ll bef = ans;
	if(dir == 0){
	    int Y = *(lower_bound(vx[x].begin(), vx[x].end(), y));
	    Y = min(Y, yr);
	    ans+= Y-1-y;
	    y = Y-1;
	    xl = x;
	}
	if(dir == 1){
	    int X = *(lower_bound(vy[y].begin(), vy[y].end(), x));
	    X = min(X, xr);
	    ans+= X-1-x;
	    x = X-1;
	    yr = y;
	}
	else if(dir == 2){
	    int Y = *(--lower_bound(vx[x].begin(), vx[x].end(), y));
	    Y = max(Y, yl);
	    ans+= y-Y-1;
	    y = Y+1;
	    xr = x;
	}
	else if(dir == 3){
	    int X = *(--lower_bound(vy[y].begin(), vy[y].end(), x));
	    X = max(X, xl);
	    ans+= x-X-1;
	    x = X+1;
	    yl = y;
	}
	dir++;
	dir%=4;
	if(frst && bef == ans)
	    break;
	frst = 1;
    }
    return cout << (ans + k == 1ll * n * m ? "Yes\n" : "No\n"), 0;
}