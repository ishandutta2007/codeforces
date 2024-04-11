// Never let them see you bleed...
// Shayan.P  2020-04-23

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

int n, a[maxn];

bool solve(){
    vector<int> vec;
    for(int i = 0; i < n; i++){
	if(i == n-1 || a[i]+1 != a[i+1])
	    vec.PB(a[i]);
    }
    for(int i = 0; i < sz(vec)-1; i++)
	if(vec[i] <= vec[i+1])
	    return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> a[i], --a[i];	    
	}
	cout << (solve() ? "Yes\n" : "No\n");
    }
}