#include <bits/stdc++.h>
#define read 			freopen("jumping.in","r",stdin)
#define write 			freopen("output.txt","w",stdout)
#define fr 				first
#define sc 				second
#define ll 				long long
#define mp 				make_pair
#define OO 				0x7fffffff
#define ii 				pair<ll,ll>
#define All(v) 			v.begin(),v.end()
#define reAssign(v, d) 	memset(v, d, sizeof(v))
#define MAX_Heap(x) 	priority_queue<x>
#define MIN_Heap(x) 	priority_queue<x, vector<x>, greater<x> >

const ll 	MOD 	= 1e9 + 7;
const int 	MAXX 	= 200000 + 2;

using namespace std;

vector<int>  p, setRank, size;
bool hasCycle[MAXX];
int n;
ll ans=1;

void DSUInit(){
	setRank.assign(MAXX, 0);
	size.assign(MAXX, 1);
	p.assign(MAXX, 0);
	for (int i = 1; i < MAXX; ++i)
		p[i] = i;
}

int DSUFindSet(int i){
	return (p[i] == i) ? i : (p[i] = DSUFindSet( p[i] ) );
}

bool DSUIsSameSet(int u, int v){
	return DSUFindSet(u) == DSUFindSet(v);
}

void DSUUnionSet(int u, int v){
	if( ! DSUIsSameSet(u, v) ){
		int i = DSUFindSet(u), j = DSUFindSet(v);
		if( setRank[i] > setRank[j] ){ 
			p[j] = p[i];
			size[i] += size[j];
			hasCycle[i] |= hasCycle[j];
		} else {
			p[i] = p[j];
			size[j] += size[i];
			if( setRank[j] == setRank[i] ) 
				setRank[j]++;
			hasCycle[j] |= hasCycle[i];
		}
		
	} else {
	    if (u!=v){
	        ans*=2;
	        ans%=MOD;
	    }
		hasCycle[DSUFindSet(u)] = true;
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	// int t;
	// cin >> t;
	// while(t--) {
		cin >> n;
		DSUInit();
		int x, y;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			DSUUnionSet(x, y);
		}
		for (int i = 1; i <= 2 * n; ++i) {
			if( p[i] != i ) continue;
			if( !hasCycle[i] ) ans = ( (ans % MOD) * (size[i] % MOD) ) % MOD;
		}
		cout << ans << endl;
	// }
	// int x;
	// cin >> x;
    return 0;
}