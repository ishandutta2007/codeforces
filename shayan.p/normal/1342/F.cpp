// Never let them see you bleed...
// Shayan.P  2020-04-26

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

pii dp[1<<15][15]; // minimum amaliat // minimum sum
int SUM[1<<15], bst[1<<15][15], a[15];
bool is[15];

void mrg(int a, int b){
    int A = 0, B = 0;
    for(int i = 0; i <= a; i++)
	A+= is[i];
    for(int i = 0; i <= b; i++)
	B+= is[i];
    is[a] = 0;
    cout << A << " " << B << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < 15; i++){	
	for(int msk = 0; msk < (1<<15); msk++){
	    if(bit(msk, i))
		bst[msk][i] = i;
	    else
		bst[msk][i] = (i == 0 ? -1 : bst[msk][i-1]);
	}
    }
    
    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> a[i];	    
	}
	for(int msk = 1; msk < (1<<n); msk++){
	    SUM[msk] = SUM[msk ^ (msk & -msk)] + a[__builtin_ctz(msk)];
	}
	for(int msk = 1; msk < (1<<n); msk++){
	    for(int i = 0; i < n; i++){
		if(__builtin_ctz(msk) <= i)
		    dp[msk][i] = {-1, SUM[msk]};
		else
		    dp[msk][i] = {inf, inf};
		for(int msk2 = msk; msk2; msk2 = (msk2-1) & msk){
		    if(msk == msk2)
			continue;
		    if(bst[msk2][i] <= 0)
			continue;
		    pii p = dp[msk ^ msk2][bst[msk2][i]-1];
		    if(SUM[msk2] > p.S)
			dp[msk][i] = min(dp[msk][i], (pii){-1+p.F, SUM[msk2]});
		}
	    }
	}
	vector<pii> vec;
	int msk = (1<<n)-1, pos = n-1;
	while(msk){
	    if(dp[msk][pos].F == -1){
		vec.PB({msk, bst[msk][pos]});
		break;
	    }		
	    for(int msk2 = msk; msk2; msk2 = (msk2-1) & msk){
		if(msk == msk2)
		    continue;
		if(bst[msk2][pos] <= 0)
			continue;
		pii p = dp[msk ^ msk2][bst[msk2][pos]-1];
		if(SUM[msk2] > p.S && dp[msk][pos] == (pii){-1+p.F, SUM[msk2]}){
		    vec.PB({msk2, bst[msk2][pos]});
		    msk = msk ^ msk2;
		    pos = bst[msk2][pos]-1;
		    break;
		}
	    }
	}
	fill(is, is + n, 1);
	cout << n - sz(vec) << "\n";
	for(pii p : vec){
	    for(int i = 0; i < n; i++)
		if(bit(p.F, i) && i != p.S)
		    mrg(i, p.S);
	}
    }
}