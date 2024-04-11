// Never let them see you bleed...
// Shayan.P  2020-06-18

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<int> v[maxn];
int col[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, m;
	cin >> n >> m;	
	for(int i = 1; i <= n; i++){
	    v[i].clear();
	    col[i] = 0;
	}
	while(m--){
	    int a, b;
	    cin >> a >> b;
	    v[b].PB(a);
	}
	vector<int> ans;
	for(int i = 1; i <= n; i++){
	    bool is0 = 0, is1 = 0;
	    for(int j : v[i]){
		is0|= col[j] == 0;
		is1|= col[j] == 1;
	    }
	    if(is1)
		col[i] = 2, ans.PB(i);
	    else if(is0)
		col[i] = 1;
	    else
		col[i] = 0;
	}
	cout << sz(ans) << "\n";
	for(int x : ans){
	    cout << x << " ";
	}
	cout << "\n";
    }
    return 0;
}