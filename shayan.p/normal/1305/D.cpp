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

vector<int> v[maxn];
bool mark[maxn];
int C, par[maxn];

void dfs(int u, int pr = -1){
    C++;
    for(int y : v[u])
	if(!mark[y] && y != pr)
	    dfs(y, u);
}
pii far(int u, int pr = -1){
    par[u] = pr;
    pii ans = {0, u};
    for(int y : v[u]){
	if(!mark[y] && y != pr){
	    pii p = far(y, u);
	    p.F++;
	    ans = max(ans, p);
	}
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);	
    }
    int r = 1;
    while(true){
	C = 0;
	dfs(r);
	if(C == 1)
	    break;
	int A = far(r).S, B = far(A).S;
	cout << "? " << A << " " << B << endl;
	int x;
	cin >> x;
	while(B != -1){
	    mark[B] = 1;
	    B = par[B];	    
	}
	mark[x] = 0;
	r = x;
    }
    cout << "! " << r <<endl;
    return 0;
}