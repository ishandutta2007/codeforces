// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-21

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

bool A[maxn], B[maxn];

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < n; i++)
	A[i] = a[i] == '1', B[i] = b[i] == '1';
    int l = 0, r = n-1;
    bool rev = 0, xr = 0;
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
	bool lst = (rev ? A[l] : A[r]) ^ xr;
	bool frs = (rev ? A[r] : A[l]) ^ xr;
	if(lst == B[i]){
	    if(rev)
		l++;
	    else
		r--;
	}
	else{
	    if(frs == B[i])
		ans.PB(1);
	    ans.PB(i+1);
	    xr^=1, rev^=1;
	    if(rev)
		l++;
	    else
		r--;
	}
    }
    cout << sz(ans) << " ";
    for(int x : ans)
	cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
    return 0;
}