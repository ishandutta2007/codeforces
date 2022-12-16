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

const int maxn=5010,mod=1e9+7;
const ll inf=1e18;

int l[maxn],r[maxn],cnt[maxn],lst[maxn],who[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,ans=0;cin>>n>>q;
    for(int i=0;i<q;i++){
	cin>>l[i]>>r[i];
	--l[i];
    }
    for(int i=0;i<q;i++){
	memset(cnt,0,sizeof cnt);
	memset(lst,0,sizeof lst);
	memset(who,0,sizeof who);
	for(int j=0;j<q;j++){
	    if(i==j) continue;
	    cnt[l[j]]++;
	    cnt[r[j]]--;
	    lst[l[j]]+=j;
	    lst[r[j]]-=j;
	}
	int LST=0,CNT=0;
	for(int j=0;j<n;j++){
	    LST+=lst[j];
	    cnt[j]+=(j==0?0:cnt[j-1]);
	    if(cnt[j]==1) who[LST]++;
	    CNT+=cnt[j]>0;
	}
	for(int j=0;j<q;j++){
	    if(j==i) continue;
	    ans=max(ans,CNT-who[j]);
	}
    }
    return cout<<ans<<endl,0;
}