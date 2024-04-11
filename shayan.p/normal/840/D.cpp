// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long double ld;
typedef pair<int,int> pll;

const int maxn=3e5+10;
const int maxk=6;
const int inf=1e9;

vector<pll>maj[4*maxn][maxk],vec;
vector<int>v[maxn];
int a[maxn];
int n;

void merge_pll(vector<pll>&a,pll b,int k){
	int Min=b.S;
	REP(i,sz(a)){
		Min=min(Min,a[i].S);
		if(a[i].F==b.F){
			a[i].S+=b.S;
			return;
		}
	}
	
	a.PB(b);
	if(sz(a)<k)
		return;
	
	stack<pll>s=stack<pll>();
	REP(i,sz(a)){
		a[i].S-=Min;
		if(a[i].S!=0)
			s.push(a[i]);
	}
	a.clear();
	while(sz(s)){
		a.PB(s.top());
		s.pop();
	}
}

void merge_vector(vector<pll>&a,vector<pll>&b,int k){
	REP(i,sz(b))
		merge_pll(a,b[i],k);
}

void build(int l=0,int r=n-1,int ind=1){
	if(l==r){
		FOR(i,2,5)
			maj[ind][i].PB(MP(a[l],1));
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,2*ind);
	build(mid+1,r,2*ind+1);
	FOR(i,2,5){
		maj[ind][i]=maj[2*ind][i];
		merge_vector(maj[ind][i],maj[2*ind+1][i],i);
	}
}

void ask(int f,int s,int k,int l=0,int r=n-1,int ind=1){
	if(l>r)return;
	if(r<f||s<l)return;
	if(f<=l&&r<=s){
		merge_vector(vec,maj[ind][k],k);
		return;
	}
	int mid=(l+r)/2;
	ask(f,s,k,l,mid,2*ind);
	ask(f,s,k,mid+1,r,2*ind+1);
}

int calc(int ind,int x){
	int l=0,r=n-1,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(sz(v[x])>mid&&v[x][mid]<=ind){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans+1;
}

int CNT(int f,int s,int x){
	return calc(s,x)-(f==0?0:calc(f-1,x));
}

int main(){
	int q;scanf("%d%d",&n,&q);
	REP(i,n){
		scanf("%d",&a[i]);
		v[a[i]].PB(i);
	}
	build();
	REP(i,q){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		l--;r--;
		int num=(r-l+1)/k;
		
		vec.clear();
		ask(l,r,k);
		int ans=inf;
		REP(i,sz(vec))
			if(CNT(l,r,vec[i].F)>num)
				ans=min(ans,vec[i].F);
		if(ans==inf)ans=-1;
		printf("%d\n",ans);
	}
}