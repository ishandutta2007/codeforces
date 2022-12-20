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

const int maxn=2e5+10,maxn2=200;

int cnt[maxn],dp[maxn];
vector<int> v[maxn2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,f;cin>>n>>f;
    
    for(int i=2;i<maxn;i++){
	if(cnt[i]==0){
	    for(int j=i;j<maxn;j+=i){
		int x=j;
		while(x%i==0) x/=i,cnt[j]++;
	    }
	}
    }
    cnt[0]=cnt[1]=cnt[f]=10;

    int MAX=0;
    
    for(int i=0;i<maxn;i++){
	for(int j=0;j<maxn2;j++){
	    bool is=0;
	    for(int x:v[j]){
		if(cnt[i-x]<=2){
		    is=1;
		    break;
		}
	    }
	    if(is==0){
		v[j].PB(i);
		dp[i]=j;
		break;
	    }
	}
	MAX=max(MAX,dp[i]);
    }
    int ans=0;
    while(n--){
	int a,b,c;cin>>a>>b>>c;
	ans^=dp[b-a-1]^dp[c-b-1];
    }
    if(ans) cout<<"Alice\nBob\n";
    else cout<<"Bob\nAlice\n";
}