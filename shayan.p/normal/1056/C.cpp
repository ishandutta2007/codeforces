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

const int maxn=2010;

set<pii>v1;
set<pair<int,pii> >v2;
int a[maxn];
int fr[maxn];
int cnt=0,t,n,m;

void used(int x){
    v1.erase({a[x],x});
    v2.erase({a[x]-a[fr[x]],{x,fr[x]}});
}
void My(){
    t^=1;
    cnt++;
    while(!v2.empty()){
	cnt+=2;
	pii p=v2.begin()->S;
	cout<<p.F<<endl;
	cin>>p.S;
	used(p.F);
	used(p.S);
    }
    if(v1.empty()) return;
    int id=v1.rbegin()->S;
    cout<<id<<endl;
    used(id);
}
void His(){
    t^=1;
    cnt++;
    int x;cin>>x;
    used(x);
    if(fr[x]!=0){
	t^=1;
	cnt++;
	cout<<fr[x]<<endl;
	used(fr[x]);
    }
}
    
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
	cin>>a[i];
    for(int i=0;i<m;i++){
	int x,y;cin>>x>>y;
	if(a[x]<a[y]) swap(x,y);
	v2.insert({a[x]-a[y],{x,y}});
	fr[x]=y;
	fr[y]=x;
    }
    for(int i=1;i<=2*n;i++){
	if(fr[i]==0){
	    v1.insert({a[i],i});
	}
    }
    cin>>t;
    if(t==2) t=0;
    while(cnt<2*n){
	if(t&1) My();
	else His();
    }
    return 0;
}