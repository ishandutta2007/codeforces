// Never let them see you bleed...
// Shayan.P  2020-05-12

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
	int n, k;
	cin >> n >> k;
	bool is1 = 0, is2 = 0;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	    is1|= a[i] == k;
	}
	for(int i = 0; i < n-1; i++){
	    is2|= (a[i] >= k && a[i+1] >= k);
	}
	for(int i = 0; i < n-2; i++){
	    is2|= (a[i] >= k && a[i+2] >= k);
	}
	is2|= (n==1);
	cout << (is1 && is2 ? "yes\n" : "no\n");
    }
    return 0;
}