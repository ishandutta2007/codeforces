#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long INT;
#define INF 0x3f3f3f3f3f3f3f3f

int xju[200005];
map<int,int> liss;
int dy[200005];
int lscnt=0;

typedef struct n0de{
	n0de *l,*r;
	INT wc;
	INT mn,fi;
	n0de(){
		l=r=0;
		mn=fi=0;
		wc=INF;
	}
}*node;

inline node newnode(){
	return new n0de();
}

inline void change(node now,int nl,int nr,int l,int r,INT x){
	if(!now->l){
		now->l=newnode();
	}
	if(!now->r){
		now->r=newnode();
	}
	if(now->wc!=INF){
		int m=(nl+nr)>>1;
		now->l->fi=now->wc*(dy[m+1]-dy[nl]);
		now->l->mn=(now->l->fi>=0?0:now->l->fi);
		now->l->wc=now->wc;
		now->r->fi=now->wc*(dy[nr+1]-dy[m+1]);
		now->r->mn=(now->l->fi>=0?0:now->r->fi);
		now->r->wc=now->wc;
		now->wc=INF;
	}
	if(nl>=l&&nr<=r){
		now->wc=x;
		now->fi=now->wc*(dy[nr+1]-dy[nl]);
		now->mn=(now->fi>=0?0:now->fi);
		return;
	}
	if(nr<l||nl>r){
		return;
	}
	int m=(nl+nr)>>1;
	change(now->l,nl,m,l,r,x);
	change(now->r,m+1,nr,l,r,x);
	now->fi=now->l->fi+now->r->fi;
	now->mn=min(now->l->mn,now->l->fi+now->r->mn);
}

inline pair<INT,INT> chmin(node now,int nl,int nr,int l,int r){
	if(l>r){
		return make_pair(0,0);
	}
	if(!now->l){
		now->l=newnode();
	}
	if(!now->r){
		now->r=newnode();
	}
	if(now->wc!=INF){
		int m=(nl+nr)>>1;
		now->l->fi=now->wc*(dy[m+1]-dy[nl]);
		now->l->mn=(now->l->fi>=0?0:now->l->fi);
		now->l->wc=now->wc;
		now->r->fi=now->wc*(dy[nr+1]-dy[m+1]);
		now->r->mn=(now->l->fi>=0?0:now->r->fi);
		now->r->wc=now->wc;
		now->wc=INF;
	}
	if(nl>=l&&nr<=r){
		return make_pair(now->mn,now->fi);
	}
	if(nr<l||nl>r){
		return make_pair(0,0);
	}
	int m=(nl+nr)>>1;
	pair<INT,INT> x=chmin(now->l,nl,m,l,r);
	pair<INT,INT> y=chmin(now->r,m+1,nr,l,r);
	return make_pair(min(x.first,x.second+y.first),x.second+y.second);
}

node root;

inline pair<INT,INT> Chmin(int l,int r){
	if(l>r){
		return make_pair(0,0);
	}
	int L=liss[l];
	map<int,int>::iterator rr=liss.upper_bound(r);
	rr--;
	int R=rr->second,rrr=rr->first;
	pair<INT,INT> x=chmin(root,0,lscnt-1,L,R-1);
	pair<INT,INT> y=chmin(root,0,lscnt-1,R,R);
	return make_pair(min(x.first,x.second+y.first/xju[R]*(r-rrr)),x.second+y.second/xju[R]*(r-rrr));
}

int q;
set<pair<int,INT> > evs;
#define spit set<pair<int,INT> >::iterator
int mmm[100005],lll[100005],rrr[100005],sss[100005];

int main(){
	root=newnode();
	evs.insert(make_pair(1000000000,0));
	evs.insert(make_pair(0,0));
	scanf("%d",&q);
	liss[0];
	liss[1000000000];
	for(int i=0;i<q;i++){
		scanf("%d",&mmm[i]);
		if(mmm[i]==1){
			scanf("%d%d",&lll[i],&sss[i]);
			liss[lll[i]];
		}else if(mmm[i]==2){
			scanf("%d",&lll[i]);
		}else{
			scanf("%d%d%d",&lll[i],&rrr[i],&sss[i]);
		}
	}
	for(map<int,int>::iterator it=liss.begin();it!=liss.end();it++){
		it->second=lscnt;
		dy[lscnt]=it->first;
		if(lscnt){
			xju[lscnt-1]=dy[lscnt]-dy[lscnt-1];
		}
		lscnt++;
	}
	xju[lscnt-1]=1;
	for(int I=0;I<q;I++){
		int mode=mmm[I];
		if(mode==1){
			int t=lll[I],s=sss[I];
			spit xx=evs.upper_bound(make_pair(t,s));
			pair<INT,INT> x=*xx;
			change(root,0,lscnt-1,liss[t],liss[x.first]-1,s);
			evs.insert(make_pair(t,s));
		}else if(mode==2){
			int t=lll[I];
			spit xx=evs.upper_bound(make_pair(t,INF));
			spit yy=xx;yy--;
			spit zz=yy;zz--;
			pair<INT,INT> x=*xx,z=*zz;
			change(root,0,lscnt-1,liss[t],liss[x.first]-1,z.second);
			evs.erase(yy);
		}else{
			int l=lll[I],r=rrr[I],v=sss[I];
			if(v==0){
				printf("%d\n",l);
				continue;
			}
			spit xxx=evs.lower_bound(make_pair(l,-INF));
			int frm=(*xxx).first;
			pair<INT,INT> fff;
			fff=Chmin(frm,r);
			INT rval=fff.first;
			if(rval+v>0){
				puts("-1");
				continue;
			}
			int L=frm,R=r;
			INT lval=0;
			while(R-L>1){
				INT m=(L+R)>>1;
				pair<INT,INT> fff=Chmin(frm,m);
				INT mnx=fff.first;
				if(mnx+v>0){
					L=m;
					lval=fff.second;
				}else{
					R=m;
					rval=fff.second;
				}
			}
			double vv;
			if(rval-lval==0){
				vv=L;
			}else{
				vv=1.00*(-v-lval)/(rval-lval)+L;
			}
			printf("%.10lf\n",vv);
		}
	}
	return 0;
}