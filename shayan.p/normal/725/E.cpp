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

const int maxn=2e5+10,inf=1e9;

map<int,int>mp;
int n,c;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>c>>n;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	mp[x]++;
    }
    for(int ans=1;ans<c;ans++){
	mp[ans]++;
	int nw=c;
	while(nw){
	    auto it=mp.upper_bound(nw);
	    while(it!=mp.begin()){
		--it;
		int dv=nw/(it->F);
		nw-=min(dv,it->S)*(it->F);
		if(dv<=(it->S)) goto Hell;
	    }
	    if(it==mp.begin()) break;
	Hell:;
	}
	if(nw!=0) return cout<<ans<<endl,0;
	if(--mp[ans]==0) mp.erase(ans);
    }
    return cout<<"Greed is good\n",0;
}