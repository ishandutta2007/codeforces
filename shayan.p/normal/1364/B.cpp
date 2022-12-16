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

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	vector<int> ans;
	for(int i = 0; i < n; i++){
	    if(i == 0 || i == n-1 || ((a[i-1] < a[i]) ^ (a[i] < a[i+1])))
		ans.PB(a[i]);
	}
	cout << sz(ans) << "\n";
	for(int x : ans)
	    cout << x << " ";
	cout << "\n";
    }
}