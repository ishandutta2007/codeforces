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

int a[maxn], ans[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    ll sm = 0;
    for(int i = 0; i < m; i++){
	cin >> a[i];
	sm+= a[i];
    }
    if(sm < n)
	return cout << -1 << endl, 0;
    int pos = n;
    for(int i = m-1; i >= 0; i--){
	pos = min(pos-1, n - a[i]);
	if(pos < 0)
	    return cout << -1 << endl, 0;
	ans[i] = pos;
    }
    int ex = ans[0], pr = 0;
    for(int i = m-2; i >= 0; i--){
	ans[i] -= pr;
	int num = min(ex, a[i] - (ans[i+1] - ans[i]));
	ans[i]-= num;
	pr+= num;
	ex-= num;
    }
    assert(ex == 0);
    for(int i = 0; i < m; i++){
	cout << ans[i]+1 << " ";
    }
    return cout << endl, 0;
}