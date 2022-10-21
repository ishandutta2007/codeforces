#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

const ll INF = 1e18;

void ckmin(ll &a, ll b){
	a = min(a, b);
}
void ckmax(ll &a, ll b){
	a = max(a, b);
}

const int mx = 2005;
int n, m;
int I[mx];
int J[mx];
int B[mx];

ll dist[205][205];
ll a[205];

bool check(){
	for(int i = 1; i <= n; i++){
		assert(0 <= a[i] && a[i] <= 1000000);
	}
	for(int i = 0; i < m; i++){
		if(B[i] == 1){
			if(a[I[i]]+1 != a[J[i]]) return 0;
		}
		else{
			if(abs(a[I[i]]-a[J[i]]) != 1) return 0;
		}
	}
	return 1;
}

void ps(string a){
	cout << a << "\n";
}

void ps(ll a){
	cout << a << "\n";
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> I[i] >> J[i] >> B[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j){
				dist[i][j] = 0;
			}
			else{
				dist[i][j] = INF;
			}
		}
	}

	for(int i = 0; i < m; i++){
		if(B[i] == 1){
			ckmin(dist[I[i]][J[i]], 1);
			ckmin(dist[J[i]][I[i]], -1);
		}
		else{
			ckmin(dist[I[i]][J[i]], 1);
			ckmin(dist[J[i]][I[i]], 1);
		}
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dist[i][k] != INF && dist[k][j] != INF) ckmin(dist[i][j], dist[i][k]+dist[k][j]);
				ckmax(dist[i][j], -INF);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(dist[i][i] < 0){
			ps("NO");
			exit(0);
		}
	}

	pair<ll, int> ans = mp(-1, -1);

	for(int i = 1; i <= n; i++){
		bool works = 1;
		for(int j = 1; j <= n; j++){
			if(dist[i][j] < 0) works = 0;
		}

		if(!works) continue;

		ll maxd = 0;
		for(int j = 1; j <= n; j++){
			ckmax(maxd, dist[i][j]);
		}
		ans = max(ans, mp(maxd, i));
	}

	if(ans.s == -1){
		ps("NO");
		exit(0);
	}

	bool works = 1;
	for(int j = 1; j <= n; j++){
		if(dist[ans.s][j] < 0) works = 0;
	}
	assert(works);

	for(int j = 1; j <= n; j++){
		a[j] = dist[ans.s][j];
	}

	if(check()){
		ps("YES");
		ll maxd = 0;
		for(int i = 1; i <= n; i++){
			ckmax(maxd, a[i]);
		}
		ps(maxd);
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	else{
		ps("NO");
	}
	exit(0);

}