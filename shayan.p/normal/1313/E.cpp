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

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int z1[maxn], z2[maxn];

struct fenwick{
    ll val[maxn];    
    void add(int pos, int x){
	for(pos+=3; pos < maxn; pos+= (pos & -pos))
	    val[pos]+= x;	
    }
    ll ask(int pos){
	ll ans = 0;
	for(pos+=3; pos > 0; pos-= (pos & -pos))
	    ans+= val[pos];
	return ans;
    }
};
fenwick fn1, fn2;

int z[2 * maxn];
void Z(string a, string b, int *arr){
    string s = b + "$" + a;    
    int L = -1, R = -1;
    for(int i = 1; i < sz(s); i++){
	if(R <= i){
	    z[i] = 0;
	    while(i + z[i] < sz(s) && s[z[i]] == s[i+z[i]])		
		z[i]++;
	}
	else{
	    z[i] = min(R-i, z[i-L]);
	    while(i + z[i] < sz(s) && s[z[i]] == s[i+z[i]])
		z[i]++;	    
	}
	if(R < i + z[i])
	    L = i, R = i+z[i];
    }
    for(int i = 0; i < sz(a); i++){
	arr[i] = z[sz(b)+1+i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    string a, b, c;
    cin >> a >> b >> c;
    Z(a, c, z1);
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    Z(b, c, z2);
    reverse(z2, z2 + n);
    for(int i = 0; i < n; i++)
	z2[i] = m-z2[i];
    for(int i = 0; i < n; i++){
	if(z1[i] == m)
	    z1[i]--;
	if(z2[i] == 0)
	    z2[i]++;
    }
    int pt = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
	pt = max(pt, i);
	while(pt < n && pt < i+m-1){
	    if(z2[pt] != m){
		fn1.add(z2[pt], 1);
		fn2.add(z2[pt], z2[pt]);
	    }
	    pt++;
	}
	if(z1[i] != 0){
	    ans+= fn1.ask(z1[i]) * (z1[i]+1) - fn2.ask(z1[i]);
	}
	if(z2[i] != m){
	    fn1.add(z2[i], -1);
	    fn2.add(z2[i], -z2[i]);
	}
    }
    return cout << ans << endl, 0;
}