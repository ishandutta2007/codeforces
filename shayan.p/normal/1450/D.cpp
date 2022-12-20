#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 3e5 + 10;

bool ans[maxn];
int a[maxn], n;
vector<int> pos[maxn];

void go(int l, int r){
    int s = r-l+1;
    if(pos[n-s+1].empty())
	return;
    ans[s] = 1;
    if(sz(pos[n-s+1]) > 1)
	return;
    if(s == 1)
	return;
    int x = pos[n-s+1].back();
    if(x == l){
	go(l+1, r);
    }
    if(x == r){
	go(l, r-1);
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
	pos[i].clear();
	ans[i] = 0;
    }
    for(int i = 1; i <= n; i++){
	pos[a[i]].PB(i);
    }
    go(1, n);
    ans[1] = 1;
    for(int i = 1; i <= n; i++){
	ans[1]&= sz(pos[i]) == 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cin >> n;
	for(int i = 1; i <= n; i++){
	    cin >> a[i];
	}
	solve();
	for(int i = 1; i <= n; i++){
	    cout << ans[i];
	}
	cout << "\n";
    }
    return 0;
}