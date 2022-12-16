// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-04

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn], b[maxn];

bool bad(int n){
    for(int i = 0; i < n-1; i++)
	if(a[i] > a[i+1])
	    return 1;
    return 0;
}
int MEX(int n){
    for(int i = 0; i < n; i++)
	b[i] = a[i];
    sort(b, b+n);
    n = unique(b, b+n) - b;
    for(int i = 0; i < n; i++)
	if(b[i] != i)
	    return i;
    return n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	int R = n;
	for(int i = 0; i < n; i++){
	    cin >> a[i];	    
	}
	vector<int> ans;
	while(bad(R)){
	    int x = MEX(R);
	    if(x != R)
		a[x] = x, ans.PB(x+1);
	    else
		ans.PB(R), a[R-1] = x, R--;
	}
	cout << sz(ans) << "\n";
	for(int x : ans)
	    cout << x << " ";
	cout << "\n";
    }
    return 0;
}