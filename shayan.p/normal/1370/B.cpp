// Never let them see you bleed...
// Shayan.P  2020-06-30

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
        vector<int> A, B;
	for(int i = 0; i < 2*n; i++){
	    cin >> a[i];
	    (a[i] & 1 ? A : B).PB(i+1);
	}
	if(sz(A) & 1)
	    A.pop_back(), B.pop_back();
	else if(sz(A))
	    A.pop_back(), A.pop_back();
	else
	    B.pop_back(), B.pop_back();
	while(sz(A))
	    cout << A.back() << " " << A[sz(A)-2] << "\n", A.pop_back(), A.pop_back();
	while(sz(B))
	    cout << B.back() << " " << B[sz(B)-2] << "\n", B.pop_back(), B.pop_back();
    }
    return 0;
}