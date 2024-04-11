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
typedef long double ld;

const int maxn=1e5+10,mod=1e9+7,inf=1e9;

int n,c,d,t[maxn],dp[2][maxn];// 0 halat kolli // 1 halat khas
char w[maxn];

struct CHT{
    ll Lazy=0,Cof=0;
    deque<pll>d;
    vector<pll>st;
    bool bad(pll a,pll b,pll c){
	return ld(a.S-b.S)*(b.F-c.F) <= ld(b.S-c.S)*(a.F-b.F);
    }
    ll gety(pll p){
	return p.F*Cof+p.S;
    }
    void Add(pll p){
	p.S-=Lazy+Cof*p.F;
	st.PB(p);
	while(sz(d)>1 && bad(d[sz(d)-2],d.back(),p))
	    d.pop_back();
	d.push_back(p);
    }
    ll Ask(){
	if(sz(d)==0) return inf;
	int l=0,r=sz(d)-1;
	ll ans=min(gety(d[0]),gety(d.back()));
	while(l<r){
	    int mid=(l+r)>>1;
	    if(gety(d[mid])<gety(d[mid+1]))
		ans=min(ans,gety(d[mid])),r=mid;
	    else
		ans=min(ans,gety(d[mid+1])),l=mid+1;
	}
	return ans+Lazy;
    }
};

struct Data{
    CHT cstart,cend;
    int pos=0;
    void Set(int vl,int cf){
	cend.Add({cf,vl});
    }
    void Upd(int ps){
	while(pos<sz(cend.st) && cend.st[pos].F-ps>d){
	    pll p={cend.st[pos].F,1ll*cend.st[pos].S+cend.Lazy+cend.Cof*cend.st[pos].F};
	    cstart.Add(p);
	    pos++;
	}
    }
    void Addt(int x){
	cend.Cof++;
	cend.Lazy-=x;
	cstart.Lazy+=d;
    }
    void Addx(int x){
	cstart.Lazy+=x;
	cend.Lazy+=x;
    }
    ll Ask(ll x){
	cend.Cof++,cstart.Cof++;
	ll Ans=min(cstart.Ask(),cend.Ask())-x;
	cend.Cof--,cstart.Cof--;
	return Ans;
    }
};Data data1,data2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>c>>d;
    for(int i=0;i<n;i++){
	cin>>t[i]>>w[i];
	t[i]*=c;
    }
    cin>>t[n];
    t[n]*=c;
    data1.Set(0,t[n]);
    data2.Set(0,t[n]);
    for(int i=n-1;i>=0;i--){
	if(w[i]=='P'){
	    data1.Upd(t[i]);
	    dp[1][i]=data1.Ask(t[i]);
	    data1.Addt(t[i]);
	    data2.Addx(d);
      	    data2.Set(dp[1][i],t[i]);
	}
	else{
	    data2.Upd(t[i]);
	    dp[1][i]=data2.Ask(t[i]);
	    data2.Addt(t[i]);
	    data1.Addx(d);
      	    data1.Set(dp[1][i],t[i]);
	}
	dp[0][i]=min(dp[1][i],dp[0][i+1]+d);
    }
    return cout<<dp[0][0]<<endl,0;
}