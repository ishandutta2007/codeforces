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

const int maxn = 1010, mod = 1e9 + 7, inf = 1e9 + 10;

int cnt[maxn];
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	vec.PB(x);
	cnt[x % m]++;
    }
    for(int i = 0; i < m; i++){
	if(cnt[i] > 1)
	    return cout << 0 << endl, 0;
    }
    int ans = 1;
    for(int i = 0; i < sz(vec); i++){
	for(int j = i+1; j < sz(vec); j++)
	    ans = 1ll * ans * abs(vec[i]-vec[j]) % m;
    }
    return cout << ans << endl, 0;
}