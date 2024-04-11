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
	int n, m;
	cin >> n >> m;
	int x1 = (n-m) / (m+1), x2 = x1+1, c2 = (n-m) % (m+1), c1 = m+1-c2;;
	cout << 1ll * n * (n+1) / 2 - 1ll * x1 * (x1+1) / 2 * c1 - 1ll * x2 * (x2+1) / 2 * c2 << "\n";
    }
    return 0;
}