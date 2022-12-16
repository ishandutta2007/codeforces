// Never let them see you bleed...
// Shayan.P  2020-06-18

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 60, mod = 1e9 + 7, inf = 1e9 + 10;

bool a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
		bool x;
		cin >> x;
		if(x)
		    a[i] = b[j] = 1;
	    }		
	}
	int A = 0, B = 0;
	for(int i = 0; i < n; i++)
	    A+= !a[i];
	for(int i = 0; i < m; i++)
	    B+= !b[i];
	cout << (min(A, B) & 1 ? "Ashish\n" : "Vivek\n");
    }
    return 0;
}