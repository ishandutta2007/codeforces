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

    int q;
    cin >> q;
    while(q--){
	ll n;
	cin >> n;
	--n;
	ll N = n/3;
	int x = n%3;
	int bt = 0;
	while(N >= (1ll<<(2*bt)))
	    N-= 1ll<<(2*bt), bt++;
	ll A =N + (1ll<<(2*bt)), B = 0, C = 0;
	for(int i = 0; i <= 30; i++){
	    int num = 2*bit(A, 2*i+1) + bit(A, 2*i);
	    if(num == 1){
		B^= 2ll<<(2*i);
		C^= 3ll<<(2*i);
	    }
	    if(num == 2){
		B^= 3ll<<(2*i);
		C^= 1ll<<(2*i);		
	    }
	    if(num == 3){
		B^= 1ll<<(2*i);
		C^= 2ll<<(2*i);
	    }
	}
	if(x == 0)
	    cout << A << "\n";
	if(x == 1)
	    cout << B << "\n";
	if(x == 2)
	    cout << C << "\n";
    }
    return 0;
}