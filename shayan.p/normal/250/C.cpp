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

int val[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, k;
    cin >> n >> k;
    vector<int> v;    
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	if(v.empty() || x != v.back())
	    v.PB(x), val[x]++;
    }
    for(int i = 1; i < sz(v)-1; i++){
	if(v[i-1] == v[i+1])
	    val[v[i]]++;
    }
    int mx = -1, ans = 1;
    for(int i = 1; i <= k; i++){
	if(mx < val[i])
	    mx = val[i], ans = i;
    }
    return cout << ans << endl, 0;
}