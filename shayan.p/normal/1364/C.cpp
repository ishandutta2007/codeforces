// Never let them see you bleed...
// Shayan.P  2020-06-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int ans[maxn], a[maxn];
bool use[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    int pt = 0;
    for(int i = 0; i < n; i++){
	ans[i] = -1;
    }
    for(int i = 0; i < n; i++){
	cin >> a[i];
	use[a[i]] = 1;
	if(pt < a[i]){
	    ans[i] = pt;
	    use[pt] = 1;
	    pt = max(pt, a[i]);
	}
    }
    pt = 1;
    for(int i = 0; i < n; i++){
	if(ans[i] == -1){
	    while(use[pt])
		pt++;
	    ans[i] = pt;
	    pt++;
	}
    }
    memset(use, 0, sizeof use);
    pt = 0;
    for(int i = 0; i < n; i++){
	use[ans[i]] = 1;
	while(use[pt])
	    pt++;
	if(pt != a[i])
	    return cout << -1 << endl, 0;
    }
    for(int i = 0; i < n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}