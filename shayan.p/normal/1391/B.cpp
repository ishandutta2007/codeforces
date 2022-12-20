// And you curse yourself for things you never done
// Shayan.P  2020-08-09

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
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i++){
	    string s;
	    cin >> s;
	    if(i == n-1){
		for(int j = 0; j < m-1; j++)
		    ans+= s[j] != 'R';
	    }
	    else{
		ans+= s.back() != 'D';
	    }
	}
	cout << ans << "\n";
    }
    return 0;
}