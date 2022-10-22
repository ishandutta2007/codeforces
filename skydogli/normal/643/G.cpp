#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define vc vector<pii>
#define fir first
#define sec second
#define MN 150005
int N;
vc Merge(vc a,vc b){
	//cerr<<"Merge: "<<a.size()<<" "<<b.size()<<endl;
	if(a.size()<b.size())swap(a,b);
	for(int i=0;i<b.size();++i){
		bool flag=0;
		for(int j=0;j<a.size();++j){
			if(a[j].sec==b[i].sec){a[j].fir+=b[i].fir;flag=1;break;}
		}
		if(!flag){
			if(a.size()<N) {a.push_back(b[i]);sort(a.begin(),a.end());continue;}
			if(a[0].fir<b[i].fir) swap(a[0],b[i]);
			for(int j=0;j<a.size();++j)a[j].fir-=b[i].fir;
		}
		sort(a.begin(),a.end());
	}
	sort(a.begin(),a.end());
	return a;
}
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
vector<pii >mx[MN<<2];
int tag[MN<<2],n,m,p,a[MN];
void build(int x,int l,int r){
	if(l==r){mx[x].push_back(mp(1,a[l]));return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	mx[x]=Merge(mx[Ls],mx[Rs]);
//	cerr<<l<<" "<<r<<": ";
//	for(int i=0;i<mx[x].size();++i)printf("%d %d, ",mx[x][i].sec,mx[x][i].fir);
//	puts("");
}
void ptag(int x,int l,int r,int v){
	tag[x]=v;
	mx[x].clear();
	mx[x].push_back(mp(r-l+1,v));
}
void pd(int x,int l,int r){
	if(tag[x]){
		ptag(Ls,l,mid,tag[x]);
		ptag(Rs,mid+1,r,tag[x]);
		tag[x]=0;
	}
}
void change(int x,int l,int r,int b,int e,int v){
	if(b<=l&&r<=e){ptag(x,l,r,v);return;}
	if(l>e||r<b)return;
	pd(x,l,r);
	if(b<=mid)change(Ls,l,mid,b,e,v);
	if(e>mid)change(Rs,mid+1,r,b,e,v);
	mx[x]=Merge(mx[Ls],mx[Rs]);
}
vector<pii >emp;
vector<pii > ask(int x,int l,int r,int b,int e){
	if(l>e||r<b)return emp;
	if(b<=l&&r<=e)return mx[x];
	pd(x,l,r);
	if(e<=mid)return ask(Ls,l,mid,b,e);
	if(b>mid)return ask(Rs,mid+1,r,b,e);
	return Merge(ask(Ls,l,mid,b,e),ask(Rs,mid+1,r,b,e));
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	N=100/p;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,1,n);
//	cerr<<"done"<<endl;
	for(int i=1;i<=m;++i){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			int id;
			scanf("%d",&id);
			change(1,1,n,l,r,id);
		}
		else {
			vc tmp=ask(1,1,n,l,r);
//			return 0;
//			cerr<<"?? "<<tmp.size()<<endl;
			int nn=tmp.size();
			printf("%d ",nn);
			for(int i=0;i<tmp.size();++i)printf("%d ",tmp[i].sec);
			puts("");
		}
	}
	return 0;
}