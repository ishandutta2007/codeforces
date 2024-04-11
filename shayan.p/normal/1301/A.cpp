// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	string a, b, c;
	cin >> a >> b >> c;
	bool ok = 1;
	for(int i = 0; i < sz(a); i++){
	    ok&= c[i] == a[i] || c[i] == b[i];
	}
	cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}