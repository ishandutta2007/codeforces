// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

bool f(string s){
    int num = 0;
    for(int i=0; i<sz(s); i++)
	num+= s[i] - '0';
    if(num % 3 != 0) return 0;
    num = 0;
    int num2 =0;
    for(int i=0; i<sz(s); i++)
	num+= s[i] == '0', num2+= (s[i] - '0') % 2 == 0;
    if(num>=1 && num2>=2) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q; cin>>q;
    while(q--){
	string s; cin>>s;
	cout<<(f(s) ? "red\n" : "cyan\n");
    }
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")