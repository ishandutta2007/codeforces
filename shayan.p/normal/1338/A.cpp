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

const int maxn = 1e5 + 10, mod = 1e9 + 7;

const ll inf = 1e18;

int a[maxn], n;

bool ok(int k){
    ll num = inf;
    for(int i = n-1; i >= 0; i--){
	if(a[i] > num)
	    return 0;
	num = min(num, a[i] + (1ll<<k) -1);	
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	cin >> n;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 0; i <= 50; i++){
	    if(ok(i)){
		cout << i << "\n";
		break;
	    }
	}
    }
    return 0;
}