#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10, lg = 31, MAX = maxn * lg;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
	if(a[i] > a[i+1])
	    return cout << 0 << endl, 0;
    }
    for(int i = 1; i <= n-2; i++){
	if(a[i] > (a[i+1] ^ a[i+2]))
	    return cout << 1 << endl, 0;
    }
    for(int i = 1; i <= n; i++){
	a[i]^= a[i-1];
    }
    int ans = n;
    for(int i = 0; i <= n; i++){
	for(int j = i+1; j <= n; j++){
	    for(int k = j+1; k <= n; k++){
		if((a[j] ^ a[i]) > (a[k] ^ a[j]))
		    ans = min(ans, k-i-2);
	    }
	}
    }
    if(ans == n)
	ans = -1;
    return cout << ans << endl, 0;
}