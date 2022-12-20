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

vector<int> v[maxn];
int H, fnd;

void dfs(int u, int par = -1, int h = 0){
    if(sz(v[u]) == 1 && u != fnd){
	if(h&1)
	    H|= 2;
	else
	    H|= 1;
    }
    for(int y : v[u]){
	if(y != par)
	    dfs(y, u, h+1);
    }
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

    for(int i = 1; i <= n; i++){
	if(sz(v[i]) == 1)
	    fnd = i;
    }
    dfs(fnd);
    
    int ans = n-1, ans2 = 3;
    for(int i = 1; i <= n; i++){
	int cnt = 0;
	for(int j : v[i])
	    cnt+= sz(v[j]) == 1;
	if(cnt > 0)
	    ans-= cnt-1;
    }
    if(H == 1)
	ans2 = 1;
    cout << ans2 << " " << ans << "\n";
    return 0;
}