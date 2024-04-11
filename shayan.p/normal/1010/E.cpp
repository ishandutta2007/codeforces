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

const int maxn=2e5+10,mod=1e9+7,inf=1e9;

map<pii,int> mp1,mp2;
vector< pair<int,pii> >tdo[maxn];
vector<pii> val[maxn];
vector<int> ids[maxn];

struct point{
    int a,b,c;
    point(int a,int b,int c):a(a),b(b),c(c){}
    point(){}
};
point max(point x,point y){
    x.a=max(x.a,y.a);
    x.b=max(x.b,y.b);
    x.c=max(x.c,y.c);
    return x;
}
point min(point x,point y){
    x.a=min(x.a,y.a);
    x.b=min(x.b,y.b);
    x.c=min(x.c,y.c);
    return x;
}
pii f(pii a,pii b){
    a.F=max(a.F,b.F);
    a.S=min(a.S,b.S);
    return a;
}
bool operator == (point a,point b){
    return a.a==b.a && a.b==b.b && a.c==b.c;
}
bool operator < (point a,point b){
    return max(a,b)==b;
}

void build(vector<pair<int,pii> >&a,vector<pii>&b){
    b.resize(2*sz(a));
    for(int i=0;i<sz(a);i++)
	b[i+sz(a)]=a[i].S;
    for(int i=sz(a)-1;i>=0;i--)
	b[i]=f(b[2*i],b[2*i+1]);
}
pii solve(vector<pii>&vec,int l,int r){// [)
    pii ans={-inf,inf};
    for(l=l+(sz(vec)/2),r=r+(sz(vec)/2);l<r;l>>=1,r>>=1){
	if(l&1) ans=f(ans,vec[l++]);
	if(r&1) ans=f(ans,vec[--r]);
    }
    return ans;
}

void print(point a){
    cout<<"( "<<a.a<<" "<<a.b<<" "<<a.c<<" )"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int X,Y,Z,n,m,q;cin>>X>>Y>>Z>>n>>m>>q;
    point mn(inf,inf,inf),mx(-inf,-inf,-inf);
    while(n--){
	point tmp;cin>>tmp.a>>tmp.b>>tmp.c;
	--tmp.a,--tmp.b,--tmp.c;
	mn=min(mn,tmp);
	mx=max(mx,tmp);
    }
    while(m--){
	point tmp;cin>>tmp.a>>tmp.b>>tmp.c;
	--tmp.a,--tmp.b,--tmp.c;
	if(mn<tmp && tmp<mx) return cout<<"INCORRECT\n",0;
	pair pp={tmp.a,tmp.b};
	if(!mp1.count(pp)) mp1[pp]=-inf,mp2[pp]=inf;////
	if(tmp.c<=mx.c) mp1[pp]=max(mp1[pp],tmp.c);
	if(mn.c<=tmp.c) mp2[pp]=min(mp2[pp],tmp.c);
    }
    for(auto IT:mp1){
	for(int id=IT.F.F+X;id>0;id>>=1)
	    tdo[id].PB({IT.F.S,{mp1[IT.F],mp2[IT.F]}});
    }
    for(int i=0;i<2*X;i++){
	sort(tdo[i].begin(),tdo[i].end());
	for(auto X:tdo[i])
	    ids[i].PB(X.F);
	build(tdo[i],val[i]);
    }
    cout<<"CORRECT\n";
    while(q--){
	point tmp;cin>>tmp.a>>tmp.b>>tmp.c;
	--tmp.a,--tmp.b,--tmp.c;
	if(mn<tmp && tmp<mx){
	    cout<<"OPEN\n";
	    continue;
	}
	point tmn=min(tmp,mn),tmx=max(tmp,mx);
	int L1=tmn.a,R1=tmx.a,L2=tmn.b,R2=tmx.b;
	pii ans={-inf,inf};
	for(int l1=L1+X,r1=R1+X+1;l1<r1;l1>>=1,r1>>=1){
	    if(l1&1){
		int l2=lower_bound(ids[l1].begin(),ids[l1].end(),L2)-ids[l1].begin();
		int r2=upper_bound(ids[l1].begin(),ids[l1].end(),R2)-ids[l1].begin();
		ans=f(ans,solve(val[l1],l2,r2));
		++l1;
	    }
	    if(r1&1){
		--r1;
		int l2=lower_bound(ids[r1].begin(),ids[r1].end(),L2)-ids[r1].begin();
		int r2=upper_bound(ids[r1].begin(),ids[r1].end(),R2)-ids[r1].begin();
		ans=f(ans,solve(val[r1],l2,r2));
	    }
	}
	if((tmn.c<=ans.F && ans.F<=tmx.c) || (tmn.c<=ans.S && ans.S<=tmx.c))
	    cout<<"CLOSED\n";
	else
	    cout<<"UNKNOWN\n";
    }
    return 0;
}