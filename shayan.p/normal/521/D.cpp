// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=1e5+10;

int a[maxn];
vector<pii>ml;
vector<pii>ad[maxn];
pii mx[maxn];

vector<pair<ll,bool> >choose[maxn];
ll sm[maxn];
int pt[maxn];

vector<int>ans;

pll fnd(int i){
    return {choose[i][pt[i]+1].F,choose[i][pt[i]].F};
}
ld ff(int i){
    pll p=fnd(i);
    return ld(p.F)/p.S;
}
struct cmp{
    bool operator()(int a,int b){
	pll A=fnd(a),B=fnd(b);
	return A.F*B.S < B.F*A.S;
    }
};
void tell(int x){
    if(x!=-1)
	ans.PB(x);
}

priority_queue<int,vector<int>,cmp>pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,m;cin>>n>>q>>m;
    for(int i=0;i<n;i++){
	cin>>a[i];
	mx[i].F=a[i];
	mx[i].S=-1;
    }
    for(int i=0;i<q;i++){
	int task,pos,val;cin>>task>>pos>>val;
	--pos;
	if(task==1 && mx[pos].F<val) mx[pos]={val,i};
	if(task==2) ad[pos].PB({val,i});
	if(task==3) ml.PB({val,i});
	ml.PB({1,-1});
    }
    sort(ml.begin(),ml.end(),greater<pii>());
    for(int i=0;i<n;i++){
	choose[i].PB({a[i],0});
	sort(ad[i].begin(),ad[i].end(),greater<pii>());
	for(int j=0;j<sz(ad[i]);j++){
	    sm[j+1]=sm[j]+ad[i][j].F;
	}
	for(int j=1;j<=sz(ad[i]);j++){
	    if(a[i]+sm[j]>=mx[i].F+sm[j-1])
		choose[i].PB({a[i]+sm[j],0});
	    else
		choose[i].PB({mx[i].F+sm[j-1],1});
	}
	choose[i].PB({choose[i].back().F-a[i]+mx[i].F,1});
	if(sz(choose[i])-1>0) pq.push(i);
    }
    int i=0;
    for(;i<m && sz(pq) && ff(pq.top())>ld(ml[m-1-i].F);i++){
	int id=pq.top();
	pq.pop();
	if(sz(choose[id])-1> ++pt[id])
	    pq.push(id);
    }
    for(int i=0;i<n;i++){
	int cnt=pt[i];
	if(choose[i][pt[i]].S)
	    tell(mx[i].S),cnt--;
	for(int j=0;j<cnt;j++)
	    tell(ad[i][j].S);
    }
    for(int j=0;j<m-i;j++){
	tell(ml[j].S);
    }
    cout<<sz(ans)<<"\n";
    for(int x:ans){
	cout<<x+1<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.