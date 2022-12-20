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

int cnt[maxn],pr[maxn],zr[maxn],a[maxn],arr[6],C;
bool is[maxn];

void Do(int x){
    C=0;
    while(x>1){
	int p=pr[x];
	arr[C++]=p;
	while(x%p==0)
	    x/=p;
    }
}

void prep(int x){
    Do(x);
    zr[0]=1;
    for(int i=1;i<(1<<C);i++)
	zr[i]=zr[i^(i & -i)]*arr[__builtin_ctz(i & -i)];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    for(int i=2;i<maxn;i++){
	if(pr[i]==0){
	    for(int j=i;j<maxn;j+=i)
		pr[j]=i;
	}
    }
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    ll ans=0;
    while(q--){
	int id;cin>>id;
	prep(a[--id]);
	for(int msk=0;msk<(1<<C);msk++){
	    if(is[id]){
		cnt[zr[msk]]--;
		ans-=1ll*(__builtin_popcount(msk)&1?-1:1)*cnt[zr[msk]];
	    }
	    else{
		ans+=1ll*(__builtin_popcount(msk)&1?-1:1)*cnt[zr[msk]];
		cnt[zr[msk]]++;
	    }
	}
	is[id]^=1;
	cout<<ans<<"\n";
    }
    return 0;
}