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

int Pow(int a, int b){
    int ans = 1;
    for(; b; b >>=1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;					   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    return cout << Pow(Pow(2, m)+mod-1, n)<< endl, 0;
}