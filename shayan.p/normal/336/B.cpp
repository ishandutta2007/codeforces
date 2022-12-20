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
typedef long double ld;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, r;
    cin >> n >> r;
    ld ans = 2;
    for(int i = 1; i <= n; i++)
	ans+= ld(4ll * i * (n-i)) / ld(1ll * n * n);
    ans+= ld(1ll * (n-1) * (-2 + sqrt(2))) / ld(n);
    ans+= ld(1ll * n * n - n - 2ll * (n-1)) * (-2 + sqrt(2)) / ld(1ll * n * n);
    ans*= r;
    return cout << setprecision(10) << fixed << ans << endl, 0;
}