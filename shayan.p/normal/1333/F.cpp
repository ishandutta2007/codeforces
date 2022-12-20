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

const int maxn = 5e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int sp[maxn], f[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    
    for(int p = 2; p <= n; p++){
	if(sp[p] == 0){
	    for(int i = p; i <= n; i+= p){
		if(sp[i] == 0)
		    sp[i] = p;
	    }
	}
	f[(p / sp[p]) + 1]++;
    }
    f[1] = 1;
    for(int i = 1; i <= n; i++){
	f[i]+= f[i-1];
    }
    
    int ans = 2;
    for(int i = 2; i <= n; i++){
	while(ans <= n && f[ans] < i)
	    ans++;
	cout << ans-1 << " ";
    }
    return cout << endl, 0;
}