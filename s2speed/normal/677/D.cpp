#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;

const int MAX_N = 300 + 20 , MAX_NM = 1e5 + 20;

bool s[MAX_NM][MAX_N];
vector<pii> v;
int a[MAX_N][MAX_N] , dis[MAX_N][MAX_N] , x = 0 , t[MAX_N] , up[MAX_N][MAX_N] , dn[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , m , p;
	cin>>n>>m>>p;
	for(int j = 0 ; j < m ; j++){
		t[j] = 0;
	}
	for(int i = 0 ; i < MAX_NM ; i++){
		for(int j = 0 ; j < MAX_N ; j++){
			s[i][j] = false;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			dis[i][j] = 2e9;
			cin>>a[i][j];
			if(!s[a[i][j]][j]){
				s[a[i][j]][j] = true;
			}
			if(a[i][j] == p){
				v.push_back({i , j});
				dis[i][j] = 0;
			}
		}
	}
	int pd = -1;
	while(x < v.size()){
		int q = v[x].first , w = v[x].second , d = a[q][w] - 1;
		if(d != pd){
			for(int j = 0 ; j < m ; j++){
				if(!s[d][j]){
					continue;
				}
				if(a[0][j] == d){
					up[0][j] = 0;
				} else {
					up[0][j] = -1;
				}
				for(int i = 1 ; i < n ; i++){
					if(a[i][j] == d){
						up[i][j] = i;
					} else {
						up[i][j] = up[i - 1][j];
					}
				}
				if(a[n - 1][j] == d){
					dn[n - 1][j] = n - 1;
				} else {
					dn[n - 1][j] = -1;
				}
				for(int i = n - 2 ; i >= 0 ; i--){
					if(a[i][j] == d){
						dn[i][j] = i;
					} else {
						dn[i][j] = dn[i + 1][j];
					}
				}
			}
			pd = d;
		}
		for(int j = 0 ; j < m ; j++){
			if(!s[d][j]){
				continue;
			}
			int it = up[q][j];
			if(it != -1){
				if(dis[it][j] == 2e9){
					v.push_back({it , j});
				}
				dis[it][j] = min(dis[q][w] + max(it - q , q - it) + max(w - j , j - w) , dis[it][j]);
			}
			it = dn[q][j];
			if(it != -1){
				if(dis[it][j] == 2e9){
					v.push_back({it , j});
				}
				dis[it][j] = min(dis[q][w] + max(it - q , q - it) + max(w - j , j - w) , dis[it][j]);
			}
		}
		x++;
	}
	int ans = 2e9;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(a[i][j] == 1){
				ans = min(ans , dis[i][j] + i + j);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}