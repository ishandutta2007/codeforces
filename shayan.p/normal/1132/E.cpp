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

ll cnt[10],arr[10],ANS,LIM;

void go(int nw=1){
    if(nw==9){
	ll SM=0;
	for(int i=1;i<=8;i++){
	    SM+=arr[i]*i;
	}
	for(int i=1;i<=8;i++){
	    ll num=SM-arr[i]*i;
	    if(num>LIM) continue;
       	    ANS=max(ANS,num+1ll*min(cnt[i],((LIM-num)/i))*i);
	}
	return;
    }
    for(ll i=0;i<=min(cnt[nw],ll(7));i++)
	arr[nw]=i,go(nw+1);
    for(ll i=max(ll(8),cnt[nw]-7);i<=cnt[nw];i++)
	arr[nw]=i,go(nw+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>LIM;
    for(int i=1;i<=8;i++){
	cin>>cnt[i];
    }
    for(int i=1;i<=4;i++){
	if(cnt[i]==0) continue;
	if(cnt[i]&1){
	    cnt[2*i]+=cnt[i]/2;
	    cnt[i]=1;
	}
	else{
	    cnt[2*i]+=(cnt[i]-2)/2;
	    cnt[i]=2;
	}
    }
    go();
    return cout<<ANS<<endl,0;
}