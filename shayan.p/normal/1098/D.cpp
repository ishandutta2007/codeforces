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

multiset<int>ms[33];
ll sm[33];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q,n=0;cin>>q;
    while(q--){
	char ch;cin>>ch;
	int x;cin>>x;
	int id=32-__builtin_clz(x);
	if(ch=='+'){
	    ms[id].insert(x);
	    for(int i=id;i<33;i++)
		sm[i]+=x;
	    n++;
	}
	else{
	    ms[id].erase(ms[id].find(x));
	    for(int i=id;i<33;i++)
		sm[i]-=x;
	    n--;
	}
	int ans=n;
	for(int i=1;i<33;i++){
	    if(!ms[i].empty() && (*ms[i].begin())>2ll*sm[i-1])
		ans--;
	}
	cout<<ans<<"\n";
    }
    return 0;
}