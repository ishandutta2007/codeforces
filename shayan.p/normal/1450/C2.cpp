#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 310;

string s[maxn];

void solve(){
    int n;
    cin >> n;
    vector<pii> v[3][2];
    for(int i = 0; i < n; i++){
	cin >> s[i];
	for(int j = 0; j < n; j++){
	    if(s[i][j] != '.'){
		v[(i + j) % 3][s[i][j] == 'X'].PB({i, j});
	    }
	}
    }
    auto f = [&](int x){
		 return sz(v[x][0]) + sz(v[x][1]);
	     };
    for(int i = 0; i < 2; i++){
	if(f(i) > f(2)){
	    swap(v[i][0], v[2][0]);
	    swap(v[i][1], v[2][1]);
	}
    }
    if(sz(v[0][0]) + sz(v[1][1]) > sz(v[0][1]) + sz(v[1][0])){
	swap(v[0][0], v[0][1]);
	swap(v[1][0], v[1][1]);
    }
    auto change = [](pii p){
		      if(s[p.F][p.S] == 'X')
			  s[p.F][p.S] = 'O';
		      else if(s[p.F][p.S] == 'O')
			  s[p.F][p.S] = 'X';
		      else
			  assert(0);
		  };
    for(pii p : v[0][0]){
	change(p);
    }
    for(pii p : v[1][1]){
	change(p);
    }
    for(int i = 0; i < n; i++){
	cout << s[i] << "\n";
    }    
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
}