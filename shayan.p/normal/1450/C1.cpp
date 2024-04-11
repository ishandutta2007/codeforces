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
    vector<pii> v[3];
    for(int i = 0; i < n; i++){
	cin >> s[i];
	for(int j = 0; j < n; j++){
	    if(s[i][j] == 'X'){
		v[(i + j) % 3].PB({i, j});
	    }
	}
    }
    int id = 0;
    for(int i = 0; i < 3; i++){
	if(sz(v[id]) > sz(v[i]))
	    id = i;
    }
    for(pii p : v[id]){
	s[p.F][p.S] = 'O';
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