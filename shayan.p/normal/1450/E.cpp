#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 210, inf = 1e6;

int dis[maxn][maxn], ans[maxn];
vector<pii> A, B;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    for(int i = 0; i < maxn; i++)
	for(int j = 0; j < maxn; j++)
	    dis[i][j] = (i == j ? 0 : inf);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	int a, b, x;
	cin >> a >> b >> x;
	--a, --b;
	if(x){
	    A.PB({a, b});
	    dis[a][b] = 1;
	    dis[b][a] = -1;
	}
	else{
	    B.PB({a, b});
	    dis[a][b] = 1;
	    dis[b][a] = 1;
	}
    }
    
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
	    for(int k = 0; k < n; k++){
		dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
		if(dis[j][k] < -inf)
		    return cout << "NO\n", 0;
	    }
	}
    }
    pii sf = {0, 0};
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
	    if(dis[sf.F][sf.S] < dis[i][j])
		sf = {i, j};
	}
    }
    for(int i = 0; i < n; i++){
	ans[i] = dis[sf.F][i];
    }
    
    for(pii p : A){
      	if(ans[p.F] + 1 != ans[p.S]){
	    return cout << "NO\n", 0;
	}
    }
    for(pii p : B){
      	if(abs(ans[p.F] - ans[p.S]) != 1){
	    return cout << "NO\n", 0;
	}
    }
    for(int i = 0; i < n; i++){
	if(ans[i] < 0)
	    return cout << "NO\n", 0;
    }
    
    cout << "YES\n" << dis[sf.F][sf.S] << "\n";
    for(int i = 0; i < n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}