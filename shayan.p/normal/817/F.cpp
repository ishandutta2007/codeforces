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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=6e5+10;

map<ll,ll> hf,hhf;

struct Container{
	short int a[3],h;
	Container(){
		h=0;
	}
	void Push(int num){
		a[h++]=num;
	}
	void Clear(){
		h=0;
	}
	void Pop(){
		h--;
	}
	int Back(){
		return a[h-1];
	}
	int Size(){
		return h;
	}
};
Container lazy[4*maxn];
ll val[4*maxn];

void Merge(Container&v,short int Lazy){
	if(Lazy==1||Lazy==2){
		v.Clear();
		v.Push(Lazy);
	}
	if(Lazy==3){
		if(v.Size()==0){
			v.Push(3);
		}
		else if(v.Back()==3){
			v.Pop();
		}
		else{
			v.Push(3);
		}
	}
}
void handle(int l,int r,int ind,int Lazy){
	if(Lazy==1){
		val[ind]=r-l+1;
	}
	if(Lazy==2){
		val[ind]=0;
	}
	if(Lazy==3){
		val[ind]=r-l+1-val[ind];
	}
}
void get(int l,int r,int ind){
	REP(i,lazy[ind].Size()){
		handle(l,r,ind,lazy[ind].a[i]);
	}
	if(l!=r){
		ll mid=(l+r)/2;
		REP(i,lazy[ind].Size()){
			Merge(lazy[2*ind],lazy[ind].a[i]);
		}
		REP(i,lazy[ind].Size()){
			Merge(lazy[2*ind+1],lazy[ind].a[i]);
		}
	}
	lazy[ind].Clear();
}
int search(int ind=1,int l=1,int r=maxn){
	if(l>r){
		return -1;
	}
	get(l,r,ind);
	if(val[ind]==r-l+1){
		return -1;
	}
	if(l==r){
		return l;
	}
	int mid=(l+r)/2;
	int num=search(2*ind,l,mid);
	if(num!=-1){
		return num;
	}
	else{
		return search(2*ind+1,mid+1,r);
	}
}
void add_lazy(int targl,int targr,short int Lazy,int ind=1,int l=1,int r=maxn){
	if(l>r)return;
	get(l,r,ind);
	if(targr<l||r<targl) return;
	if(targl<=l&&r<=targr){
		lazy[ind].Push(Lazy);
		get(l,r,ind);
		return;
	}
	int mid=(l+r)/2;
	add_lazy(targl,targr,Lazy,2*ind,l,mid);
	add_lazy(targl,targr,Lazy,2*ind+1,mid+1,r);
	val[ind]=val[2*ind]+val[2*ind+1];
}
int main(){
	int q;cin>>q;
	ll t[q+10],l[q+10],r[q+10];
	set<ll> s;
	s.insert(1);
	REP(i,q){
		cin>>t[i]>>l[i]>>r[i];
		s.insert(l[i]);
		s.insert(r[i]);
		s.insert(l[i]+1);
		if(l[i]>1) s.insert(l[i]-1);
		s.insert(r[i]+1);
		if(r[i]>1) s.insert(r[i]-1);
	}
	ll h=1;
	for(set<ll>::iterator it=s.begin();it!=s.end();it++){
		hf[*it]=h;
		hhf[h]=(*it);
		h++;
	}
	REP(i,q){
		add_lazy(hf[l[i]],hf[r[i]],t[i]);
		cout<<hhf[search()]<<endl;
	}
}