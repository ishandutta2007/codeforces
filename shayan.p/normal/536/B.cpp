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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int f[maxn],Cnt=0;
bool good[maxn],is[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    for(int i=2;i<=sz(s);i++){
	f[i]=f[i-1];
	while(f[i]>0 && s[f[i]]!=s[i-1]) f[i]=f[f[i]];
	f[i]+=s[f[i]]==s[i-1];
    }
    int tmp=f[sz(s)];
    while(tmp>0){
	good[tmp]=1;
	tmp=f[tmp];
    }
    good[0]=1;
    for(int i=0;i<m;i++){
	int x;cin>>x;
	is[--x]=1;
    }
    int nw=0;
    for(int i=0;i<n;i++,nw=max(0,nw-1)){
	if(is[i]){
	    if(good[nw]==0) return cout<<0<<endl,0;
	    nw=sz(s);
	}
	if(nw==0) Cnt++;
    }
    int ans=1;
    while(Cnt--){
	ans=1ll*ans*26 %mod;
    }
    return cout<<ans<<endl,0;
}