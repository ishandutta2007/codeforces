// Phoenix

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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

ll cnt[maxn],bef,ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,pt=0;cin>>n>>k;
    string a,b;cin>>a>>b;
    while(pt<n && a[pt]==b[pt]) pt++,ans++;
    if(k==1){
	return cout<<ans+n-pt<<endl,0;
    }
    if(k==2){
	return cout<<ans+n+n-pt-pt<<endl,0;
    }
    ans+=n+n-pt-pt;
    k-=2;
    for(int i=pt+1;i<n;i++){
	if(a[i]=='a')
	    cnt[n-i]++;
    }
    for(int i=pt+1;i<n;i++){
	if(b[i]=='b')
	    cnt[n-i]++;
    }
    for(int i=maxn-1;i>0;i--){
	if((cnt[i]+bef)>=k){
	    ans+=1ll*i*k;
	    break;
	}
	ans+=1ll*i*(cnt[i]+bef);
	k-=cnt[i]+bef;
	bef=2*bef+cnt[i];
    }
    cout<<ans<<endl;
    return 0;
}