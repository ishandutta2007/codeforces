#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
//typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
const int maxn=1000100;
struct tree{
	int l,r,s,xl,xr,y,mxv;
	tree(){
	}
};
tree t[maxn];   
int kv,n,root,x,l0,r0,m,aa,bb,cc,q,ll,rr,ff,gg,f1,f2,x0,g1,g2;
inline void push(int v){

}
inline int getl(int v){
	return t[v].xr-t[v].xl;
}
bool hh;
inline void calc(int v){
	t[v].s=(v!=0)+t[t[v].l].s+t[t[v].r].s;
	if (getl(t[t[v].l].mxv)>getl(t[t[v].r].mxv)){
		t[v].mxv=t[t[v].l].mxv;
		hh=true;
	} else {
		t[v].mxv=t[t[v].r].mxv;
		hh=false;
	}
	if (getl(v)>getl(t[v].mxv) || (getl(v)==getl(t[v].mxv) && hh)){
		t[v].mxv=v;
	}
}

void split(int v,int x,int& ll,int& rr){
	ll=0;
	rr=0;
	if (v==0)
		return;
	push(v);
	if (t[v].xr<=x){
		split(t[v].r,x,t[v].r,rr);
		calc(ll=v);
	} else {
		split(t[v].l,x,ll,t[v].l);
		calc(rr=v);
	}
}
int merge(int ll,int rr){
	if (ll==0 || rr==0)
		return ll+rr;
	if (t[ll].y<t[rr].y){
		push(rr);
		t[rr].l=merge(ll,t[rr].l);
		calc(rr);
		return rr;
	} else {
		push(ll);
	    t[ll].r=merge(t[ll].r,rr);
		calc(ll);
		return ll;
	}
}
int fnd(int v,int x){
	if (v==0) return -1;
	if (x>=t[v].xl && x<=t[v].xr){
		return v;
	}
	if (x<t[v].xl) return fnd(t[v].l,x);
			else   return fnd(t[v].r,x);
}
map<int,int> stt;
void add(int ll,int rr){
	kv++;
	t[kv].xl=ll;
	t[kv].xr=rr;
	t[kv].y=(rand() << 15) + rand();
	t[kv].s=1;
	t[kv].mxv=kv;	
	split(root,ll,aa,bb);
	aa=merge(aa,kv);
	root=merge(aa,bb);
}
void del(int v){
	split(root,t[v].xl-1,aa,bb);
	split(bb,t[v].xr,bb,cc);
//	cerr<<aa<<" "<<bb<<" "<<cc<<endl;
	root=merge(aa,cc);
}
void printv(int v){
	if (v==0) return;
	cerr<<v<<"["<<t[v].xl<<" "<<t[v].xr<<"]"<<" "<<t[v].mxv<<endl;
	printv(t[v].l);
	cerr<<"|"<<endl;
	printv(t[v].r);
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    srand(239);
    memset(t,0,sizeof(t));
	scanf("%d%d",&n,&q);
	root=1;
	t[1].xl=1;
	t[1].xr=n+1;
	t[1].y=(rand() << 15) + rand();
	t[1].s=1;
	t[1].mxv=1;
	kv=1;
	for (int it=0;it<q;it++){
		scanf("%d",&x);
//		if (it==13) printv(root);
		if (x==0){	
			scanf("%d%d",&ll,&rr);
			//rr++;
			ll--;
//			rr++;			
			split(root,ll,aa,bb);
			split(bb,rr,bb,cc);
			printf("%d\n",t[bb].s);
			aa=merge(aa,bb);
			root=merge(aa,cc);
		} else {
			if (stt[x]!=0){
				ff=stt[x];
				stt[x]=0;
				f1=fnd(root,ff);
				f2=fnd(root,ff+1);
				g1=t[f1].xl;
				g2=t[f2].xr;
				del(f1);
				del(f2);
				add(g1,g2);
			} else {
				ff=t[root].mxv;
				x0=x;
				x=(t[ff].xl+t[ff].xr)/2;
				//if ((-t[ff].xl+t[ff].xr)%2==0){
			//		x++;
		//		}
		//		cerr<<t[ff].xl<<" "<<t[ff].xr<<endl;
	//			cerr<<x<<endl;
				stt[x0]=x;
				g1=t[ff].xl;
				g2=t[ff].xr;
				del(ff);
				//		printv(root);
				//cerr<<endl;
				add(g1,x);
				add(x+1,g2);
			}
		}
		//printv(root);
		//cerr<<endl;
		//if (it==1) return 0;
	}
    return 0;
}