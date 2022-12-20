#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 110, inf = 1e9;

int a[maxn], b[maxn];

int solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
	cin >> a[i+1], a[i+1]+= a[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
	cin >> b[i+1], b[i+1]+= b[i];
    int ans = 0;
    for(int i = 0; i <= n; i++)
	for(int j = 0; j <= m; j++)
	    ans = max(ans, a[i] + b[j]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
}