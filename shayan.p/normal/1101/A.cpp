// Mikaeel_noob_e_sag_e

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    int n;cin>>n;
    while(n--){
	int a,b,c;cin>>a>>b>>c;
	if(c<a) cout<<c<<"\n";
	else cout<<((b/c)+1)*c<<"\n";
    }
    return 0;
}