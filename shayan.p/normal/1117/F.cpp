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

const int maxn=1e5+10,mod=1e9+7,M=17;
const ll inf=1e18;

bool is[M][M];
int lst[M],cnt[M],Size[1<<M];
bool bd[1<<M],gd[1<<M];
vector<int>tdo[1<<M];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,p;cin>>n>>p;
    string s;cin>>s;
    for(int i=0;i<p;i++)
	for(int j=0;j<p;j++)
	    cin>>is[i][j];
    memset(lst,-1,sizeof lst);
    for(int i=0;i<n;i++){
	for(int j=0;j<p;j++){
	    if(lst[j]==-1) continue;
	    if(is[j][s[i]-'a']==0){
		int msk=0;
		for(int k=0;k<p;k++){
		    if(lst[k]>lst[j])
			msk|=(1<<k);
		}
		tdo[((1<<p)-1)^msk^((1<<(j))|(1<<(s[i]-'a')))].PB((1<<j) | (1<<(s[i]-'a')));	
	    }
	}
	lst[s[i]-'a']=i;
	cnt[s[i]-'a']++;
    }
    for(int msk=0;msk<(1<<M);msk++){
	if(tdo[msk].empty()) continue;
	for(int mmsk=msk,Tot=msk;;mmsk=(mmsk-1)&Tot){
	    for(int x:tdo[msk])
		bd[mmsk | x]=1;
	    if(mmsk==0)break;
	}
    }
    for(int i=0;i<(1<<p);i++){
	for(int j=0;j<p;j++){
	    if(bit(i,j))
		Size[i]+=cnt[j];
	}
    }
    int ans=n+1;
    for(int i=(1<<p)-1;i>=0;i--){
	if(bd[i]) continue;
	for(int j=0;j<p;j++){
	    if(!bit(i,j))
		gd[i]|=gd[i ^ (1<<j)];
	}
	if(i==(1<<p)-1) gd[i]=1;
	if(gd[i]) ans=min(ans,Size[i]);
    }
    return cout<<ans<<endl,0;
}