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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,mx1=0,mx2=0;cin>>n;
    while(n--){
	char ch;cin>>ch;
	int a,b;cin>>a>>b;
	if(a>b) swap(a,b);
	if(ch=='+')
	    mx1=max(mx1,a),mx2=max(mx2,b);
	else
	    cout<<(mx1<=a && mx2<=b ? "YES" : "NO")<<"\n";
    }
}