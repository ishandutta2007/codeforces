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

int cnt[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int a, b, c;
	cin >> a >> b >> c;

	int ans = 0;
	for(int msk = 0; msk < (1<<7); msk++){
	    memset(cnt, 0, sizeof cnt);
	    for(int i = 0; i < 7; i++){
		if(bit(msk, i))
		    for(int j = 0; j < 3; j++)
			if(bit(i+1, j))
			    cnt[j]++;		    
	    }
	    if(cnt[0] <= a && cnt[1] <= b && cnt[2] <= c)
		ans = max(ans, __builtin_popcount(msk));
	}
	cout << ans << "\n";
    }
    return 0;
}