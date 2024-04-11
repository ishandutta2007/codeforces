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
	int n, x, y;
	cin >> n >> x >> y;
	int A = max(int(0), x+y-n - (y == n && x == n)), B = max(int(0), x+y-1-n) + min(x-1, n-y) + min(y-1, n-x);
	cout << A+1 << " " << B+1 << "\n";
    }
    return 0;
}