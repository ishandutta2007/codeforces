#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	puts("2000");
	rep(i,1,1001){
		printf("%d 1 %d 2\n", i, i);
	}
	rrep(i,1001,1){
		printf("%d 1 %d 2\n", i, i);
	}
	/*int sw=0;
	rep(i,3,N+3){
		if(i%2){
			sw^=1;
			printf("%d %d %d %d\n", i/2, 1+sw, i/2+1, 2-sw);
		}
		else{
			printf("%d %d %d %d\n", i/2, 1+sw, i/2-1, 2-sw);
		}
	}*/
}