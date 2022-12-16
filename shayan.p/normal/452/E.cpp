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

const int maxn=3e5+10,Log=20,mod=1e9+7;

int rnk[Log][maxn],ans[maxn],id[maxn],par[maxn],Cnt[4][maxn];
ll score[maxn],ANS;
pair<pii,int>arr[maxn];
vector<int>h[maxn];
string s;

int LCP(int a,int b){
    int ans=0;
    for(int i=Log-1;i>=0;i--){
	if(a+(1<<i)<=sz(s) && b+(1<<i)<=sz(s) && rnk[i][a]==rnk[i][b])
	    ans+=(1<<i),a+=(1<<i),b+=(1<<i);
    }
    return ans;
}

int Find(int u){
    return (par[u]<0?u:par[u]=Find(par[u]));
}
void Merge(int a,int b){
    if((a=Find(a))==(b=Find(b))) return;
    if(par[a]>par[b]) swap(a,b);
    for(int i=0;i<4;i++){
	Cnt[i][a]+=Cnt[i][b];
    }
    ANS-=score[a]+score[b];
    score[a]=1ll*Cnt[0][a]*Cnt[1][a] %mod *Cnt[2][a] %mod;
    ANS=(ANS+score[a])%mod;
    par[a]+=par[b];
    par[b]=a;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a,b,c;cin>>a>>b>>c;
    int L=min(sz(a),min(sz(b),sz(c)));
    for(int i=0;i<sz(a);i++){
	id[sz(s)]=0;s+=a[i];
    }
    id[sz(s)]=3,s+='1';
    for(int i=0;i<sz(b);i++){
	id[sz(s)]=1;s+=b[i];
    }
    id[sz(s)]=3,s+='2';
    for(int i=0;i<sz(c);i++){
	id[sz(s)]=2;s+=c[i];
    }
    for(int i=0;i<sz(s);i++){
	rnk[0][i]=s[i];
	par[i]=-1;
	Cnt[id[i]][i]++;
    }
    for(int i=1;i<Log;i++){
	for(int j=0;j<sz(s);j++){
	    arr[j]={{rnk[i-1][j],j+(1<<(i-1))>=sz(s)?-1:rnk[i-1][j+(1<<(i-1))]},j};
	}
	sort(arr,arr+sz(s));
	for(int j=1;j<sz(s);j++){
	    rnk[i][arr[j].S]=rnk[i][arr[j-1].S]+(arr[j-1].F!=arr[j].F);
	}
    }
    for(int i=0;i<sz(s)-1;i++){
	h[LCP(arr[i].S,arr[i+1].S)].PB(i);
    }
    for(int i=maxn-1;i>=0;i--){
	for(int x:h[i]){
	    Merge(arr[x].S,arr[x+1].S);
	}
	ans[i]=(ANS+mod)%mod;
    }
    for(int i=1;i<=L;i++){
	cout<<ans[i]<<" ";
    }
    return cout<<endl,0;
}