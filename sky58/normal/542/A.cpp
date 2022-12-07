#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 262144
int A[252521],B[252521],L[252521],R[252521];
lint C[252521];
vector<pint> p,q;
vector<int> x,y;
int inf=1145141919;
int dat[N*2+10];
int query(int a,int b,int k=0,int l=0,int r=N){
	if(r<=a || b<=l) return -inf;
	if(a<=l && r<=b) return dat[k];
	int vl=query(a,b,k*2+1,l,(l+r)/2);
	int vr=query(a,b,k*2+2,(l+r)/2,r);
	return max(vl,vr);
}
int main()
{
	int n,m,id=-1,r=0;lint out=0;
	cin>>n>>m;
	rep(i,n){
		//cin>>L[i]>>R[i];
		scanf("%d %d",&L[i],&R[i]);
		p.pb(mp(L[i],-R[i]));
	}
	sort(All(p));
	rep(i,n){
		if(-p[i].se>r){
			q.pb(p[i]);
			r=-p[i].se;
		}
	}
	rep(i,q.size()) x.pb(q[i].fi),y.pb(-q[i].se);
	rep(i,N*2+10) dat[i]=-inf;
	rep(i,q.size()) dat[N-1+i]=-q[i].fi-q[i].se;
	for(int i=N-2;i>=0;i--) dat[i]=max(dat[i*2+1],dat[i*2+2]);
	rep(i,m){
		//cin>>A[i]>>B[i]>>C[i];
		scanf("%d %d %d",&A[i],&B[i],&C[i]);
		int lo=lower_bound(All(x),A[i])-x.begin();
		int hi=lower_bound(All(y),B[i]+1)-y.begin();
		lint ret=C[i]*query(lo,hi);
		if(lo>0){
			ret=max(ret,C[i]*(min(B[i],-q[lo-1].se)-A[i]));
		}
		if(hi<q.size()){
			ret=max(ret,C[i]*(B[i]-max(A[i],q[hi].fi)));
		}
		if(out<ret){out=ret;id=i;}
	}
	cout<<out<<endl;
	if(out>0){
		rep(i,n){
			if(C[id]*(min(B[id],R[i])-max(A[id],L[i]))==out){
				cout<<i+1<<' '<<id+1<<endl;
				break;
			}
		}
	}
}