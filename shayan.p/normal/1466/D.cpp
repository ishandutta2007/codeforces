#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int w[maxn], arr[maxn], d[maxn];
ll ret[maxn];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> w[i];
	arr[i] = i;
	d[i] = 0;
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	d[a]++, d[b]++;
	ans+= w[a] + w[b];
    }
    sort(arr + 1, arr + n + 1, [](int i, int j){ return w[i] < w[j]; });
    int pt = n-2;
    ret[n-1] = ans;
    for(int i = 1; i <= n; i++){
	int u = arr[i];
	while(d[u] > 1){
	    ans-= w[u];
	    d[u]--;
	    ret[pt] = ans;
	    pt--;
	}
    }
    for(int i = 1; i <= n-1; i++){
	cout << ret[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
}