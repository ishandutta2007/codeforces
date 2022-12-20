#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10, SQ = 300;

vector<pii> pr[maxn];
vector<int> v[maxn];
int cnt[maxn];

void print(int a, int b){
    cout << a+1 << " " << b+1 << "\n";
}
int both(vector<int> &vec){
    int ans = 0;
    for(int x : vec)
	ans+= cnt[x];
    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<int> All;
    for(int i = 0; i < n; i++){
	int k;
	cin >> k;
	v[i].resize(k);
	for(int j = 0; j < k; j++)
	    cin >> v[i][j], All.PB(v[i][j]);
	sort(v[i].begin(), v[i].end());
    }
    sort(All.begin(), All.end());
    All.resize( unique(All.begin(), All.end()) - All.begin() );
    for(int i = 0; i < n; i++){
	for(int &x : v[i]){
	    x = lower_bound(All.begin(), All.end(), x) - All.begin();
	}
    }
    int N = sz(All);
    for(int i = 0; i < N; i++){
	pr[i].clear();
    }
    for(int i = 0; i < n; i++){
	if(sz(v[i]) > SQ){
	    for(int x : v[i]){
		cnt[x]++;
	    }
	    for(int j = 0; j < n; j++){
		if(j == i)
		    continue;
		if(both(v[j]) >= 2){
		    print(i, j);
		    for(int x : v[i]){
			cnt[x] = 0;
		    }		    
		    return;
		}
	    }
	    for(int x : v[i]){
		cnt[x] = 0;
	    }
	}
	else{
	    for(int w = 0; w < sz(v[i]); w++){
		for(int w2 = w+1; w2 < sz(v[i]); w2++){
		    int A = v[i][w], B = v[i][w2];
		    if(A > B)
			swap(A, B);
		    pr[A].PB({B, i});
		}
	    }
	}
    }
    for(int val = 0; val < N; val++){
	for(pii p : pr[val]){
	    cnt[p.F] = p.S;
	}
	for(pii p : pr[val]){
	    if(cnt[p.F] != p.S){
		print(cnt[p.F], p.S);
		for(pii p : pr[val]){
		    cnt[p.F] = 0;
		}
		return;
	    }
	}
	for(pii p : pr[val]){
	    cnt[p.F] = 0;
	}
    }
    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }	
}