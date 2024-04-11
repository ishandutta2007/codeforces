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

    int n;
    cin >> n;
    int ans = 0;
    for(int a = 1; a <= n; a++){
	int c = 1;
	for(int b = a; b <= n; b++){
	    while(c * c < a*a + b*b)
		c++;
	    if(c > n)
		break;
	    if(a*a + b*b == c*c)
		ans++;
	}
    }
    return cout << ans << endl, 0;
}