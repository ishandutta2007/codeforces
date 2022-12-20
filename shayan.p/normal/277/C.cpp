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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

map<int,vector<pii> >mp[2];// 0 ofoghi // 1 amoodi
map<int,int> gr[2];
vector<int>vv,sm;

void prep(vector<pii>&vec,int n){
    vv.clear();sm.clear();
    for(pii p:vec){
	vv.PB(p.F);
	vv.PB(p.S);
    }
    vv.PB(0);vv.PB(n);
    sort(vv.begin(),vv.end());
    vv.resize(unique(vv.begin(),vv.end())-vv.begin());
    sm.resize(sz(vv),0);
    for(pii p:vec){
	sm[lower_bound(vv.begin(),vv.end(),p.F)-vv.begin()]++;
	sm[lower_bound(vv.begin(),vv.end(),p.S)-vv.begin()]--;
    }
}

int calc(vector<pii>&vec,int n){
    prep(vec,n);
    int ans=0,nw=sm[0];
    for(int i=1;i<sz(vv);i++){
	if(nw==0) ans+=vv[i]-vv[i-1];
	nw+=sm[i];
    }
    return ans;
}

int Do(vector<pii>&vec,int n,int l){
    prep(vec,n);
    int ans=0,nw=sm[0];
    for(int i=1;i<sz(vv);i++){
	if(nw==0){
	    if(ans+vv[i]-vv[i-1]>=l) return vv[i-1]+l-ans;
	    ans+=vv[i]-vv[i-1];
	}
	nw+=sm[i];
    }
    return -3;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<k;i++){
	int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
	if(y1>y2) swap(y1,y2);
	if(x1>x2) swap(x1,x2);
	if(x1==x2) mp[0][x1].PB({y1,y2});
	else mp[1][y1].PB({x1,x2});
    }
    int isnx=-1,isny=-1,Count=1;
    for(auto &x:mp[0]){
	if(x.F!=Count) break;
	Count++;
    }
    isnx=Count;
    Count=1;
    for(auto &x:mp[1]){
	if(x.F!=Count) break;
	Count++;
    }
    isny=Count;
    int ans=0;
    
    if((n^1^sz(mp[0]))&1){
	gr[0][isnx]=m;
	ans^=m;
    }
    if((m^1^sz(mp[1]))&1){
	gr[1][isny]=n;
	ans^=n;
    }
    for(auto &x:mp[0]){
	int num=calc(x.S,m);
	ans^=num;
	gr[0][x.F]=num;
    }
    for(auto &x:mp[1]){
	int num=calc(x.S,n);
	ans^=num;
	gr[1][x.F]=num;
    }
    
    if(ans==0) return cout<<"SECOND\n",0;
    cout<<"FIRST\n";
    int id=31-__builtin_clz(ans);
    for(auto x:gr[0]){
	if(bit(x.S,id)){
	    int pos=Do(mp[0][x.F],m,x.S-(ans^x.S));
	    return cout<<x.F<<" "<<0<<" "<<x.F<<" "<<pos<<"\n",0;
	}
    }
    for(auto x:gr[1]){
	if(bit(x.S,id)){
	    int pos=Do(mp[1][x.F],n,x.S-(ans^x.S));
	    return cout<<0<<" "<<x.F<<" "<<pos<<" "<<x.F<<"\n",0;
	}
    }
    return 0;
}