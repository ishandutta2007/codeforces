// In the name of God

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

const int maxn=2010;

int n,A,B,a[maxn];
vector<pii>v;
deque<pii>vec;
vector<deque<pii> >g;
vector<pii>solve;
bool need[maxn],here[maxn];
int pt,pt2;

void NO(){
    cout<<"NO"<<endl;
    exit(0);
}

void Remove(){
    //cout<<"HEY CALLING "<<sz(vec)<<endl;
    while(!vec.empty() && vec.back().S==pt){
	if(vec.back().S-vec.back().F>=B)
	    NO();
	solve.PB({2,vec.back().S-vec.back().F+1});
	pt=vec.back().F-1;
	vec.pop_back();
    }
}

void Add(int x){
    //    cout<<"ADDING "<<x<<endl;
    int END=pt2+x;
    if(x>A) NO();
    solve.PB({1,x});
    while(!vec.empty() && x>0 && vec.back().F-1==a[pt2+x-1]){
	--vec[sz(vec)-1].F;
	--x;
    }
    if(x>0 && !vec.empty() && a[pt2+x-1]<vec.back().F) NO();
    vector<pii>vv;
    for(int i=0;i<x;i++){
	if(!vv.empty() && a[pt2+i]==vv.back().S+1)
	    vv[sz(vv)-1].S++;
	else
	    vv.PB({a[pt2+i],a[pt2+i]});
    }
    for(int i=0;i<sz(vv)-1;i++){
	if(vv[i].F<vv[i+1].S)
	    NO();
    }
    for(int i=sz(vv)-1;i>=0;i--){
	//	cout<<"ADDED "<<vv[i].F<<" "<<vv[i].S<<endl;
	vec.PB(vv[i]);
    }
    pt2=END;
}

int main(){
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=1;i<=n;i++){
	if(!v.empty() && a[i]==v.back().S+1)
	    v[sz(v)-1].S++;
	else
	    v.PB({a[i],a[i]});
    }
    for(int i=0;i<sz(v);i++){
	if(!g.empty() && g.back().back().F>v[i].S)
	    g[sz(g)-1].PB(v[i]);
	else
	    vec.clear(),vec.PB(v[i]),g.PB(vec);
    }
    pt=n;
    for(deque<pii> v:g){
	bool ys=1;
	for(pii p:v){
	    for(int i=p.F;i<=p.S;i++)
		here[i]=1;
	}
	while(here[pt])
	    pt--;
	if(v.back().F>=pt) continue;
	int nw=sz(v)-1;
	for(int i=sz(v)-1;i>=1;i--){
	    if(v[i-1].F>=pt) break;
	    nw=i-1;
	    ys&=v[i].S+1==v[i-1].F;
	}
	if(v[0].F<pt) nw=0;
	if(ys){
	    if(here[v[nw].S+1])
		need[v[nw].S+1]=1;
	}
	else{
	    if(sz(v)>1 && v[sz(v)-1].S+1!=v[sz(v)-2].F && pt>v[sz(v)-1].S+1 && here[v[sz(v)-1].S+1])
		need[v[sz(v)-1].S+1]=1;
	}
    }
    pt=n;
    pt2=1;
    vec.clear();
    for(deque<pii> v:g){
	/*
	cout<<"HELLO \n";
	for(pii p:v)
	    cout<<p.F<<" "<<p.S<<endl;
	cout<<endl<<endl;
	*/
	while(!v.empty() && v[0].S==pt){
	    for(int j=0;j<(v[0].S-v[0].F+1);j++)
		Add(1);
	    Remove();
	    v.pop_front();
	}
	bool ys=1;
	for(int j=0;j<sz(v)-1;j++){
	    ys&=(v[j].F)==(v[j+1].S+1);
	}
	int sm=0;
	for(pii p:v)
	    sm+=p.S-p.F+1;
	//	cout<<"SM "<<"YS "<<sm<<" "<<ys<<endl;
	if(sz(v)==1){
	    if(need[v.back().F] || (!vec.empty() && vec.back().F>v.back().S)){
		Add(sm);
	    }
	    else{
		for(int i=0;i<sm;i++)
		    Add(1);
	    }
	}
	else if(sz(v)==2){
	    if(ys){
		int ln1=v[0].S-v[0].F+1,ln2=v[1].S-v[1].F+1;
		if(need[v.back().F] || (!vec.empty() && vec.back().F>v.back().S)){
		    //		    cout<<v.back().F<<"    "<<need[v.back().F]<<endl;
		    Add(ln1);
		    Add(ln2);
		}
		else{
		    if(sm<=A && ln1<=B && ln2<=B){
			Add(sm);
		    }
		    else if(ln1<=A && ln2<=A && sm<=B){
			Add(ln1);
			Add(ln2);
		    }
		    else if(max(1,max(sm-A,ln1-B))<=min(ln1-1,min(A,B-ln2))){
			int X=max(1,max(sm-A,ln1-B));
			Add(X);
			Add(sm-X);
		    }
		    else if(max(1,max(ln2-A,sm-B))<=min(ln2-1,min(A-ln1,B))){
			int X=max(1,max(ln2-A,sm-B));
			Add(ln1+X);
			Add(ln2-X);
		    }
		    else{
			NO();
		    }
		}
	    }
	    else{
		Add(sm);
	    }
	}
	else if(sz(v)>2){
	    if(ys && (need[v.back().F] || (!vec.empty() && vec.back().F>v.back().S) || sm>A)){
		for(int i=0;i<sz(v);i++)
		    Add(v[i].S-v[i].F+1);
	    }
	    else{
		Add(sm);
	    }
	}
    }
    cout<<"YES\n"<<sz(solve)<<endl;
    for(pii p:solve){
	cout<<p.F<<" "<<p.S<<endl;
    }
    return 0;
}