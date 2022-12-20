// Wanna Hack? GL...

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
    int q;cin>>q;
    while(q--){
	int x;cin>>x;
	int num=32-__builtin_clz(x),ans=1;
	if((1<<num)-1==x){
	    for(int i=2;i*i<=x;i++){
		if(x%i==0){
		    ans=x/i;
		    break;
		}
	    }
	}
	else{
	    ans=(1<<num)-1;
	}
	cout<<ans<<"\n";
    }
}