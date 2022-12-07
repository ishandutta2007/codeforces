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
#define N 131072
int inf=1145141919;
pint dat[N*2+10];
int a[N];
pint query(int a,int b,int k=0,int l=0,int r=N){
	if(r<=a || b<=l) return mp(-inf,-inf);
	if(a<=l && r<=b) return dat[k];
	pint vl=query(a,b,k*2+1,l,(l+r)/2);
	pint vr=query(a,b,k*2+2,(l+r)/2,r);
	return max(vl,vr);
}
void update(int k,pint a){
	k+=N-1;
	dat[k]=a;
	while(k>0){
		k=(k-1)/2;
		dat[k]=max(dat[k*2+1],dat[k*2+2]);
	}
	return;
}
template <class typ> struct BIT{
	vector<typ> x;
	BIT(int n):x(n,0){}
	typ sum(int a,int b){
		if(a==0){
			typ s=0;
			for(int i=b;i>=0;i=(i&(i+1))-1) s+=x[i];
			return s;
		}
		else return sum(0,b)-sum(0,a-1);
	}
	void add(int ind,typ f){
		for(int i=ind;i<x.size();i|=i+1) x[i]+=f;
	}
};
int main()
{
	int n,m,l,r,x,t;
	cin>>n>>m;
	BIT<lint> bit(n+10);
	rep(i,N*2+5) dat[i]=mp(-inf,-inf);
	rep(i,n){
		cin>>a[i];update(i,mp(a[i],i));bit.add(i,a[i]);
	}
	rep(i,m){
		//rep(j,m) cout<<a[j]<<' ';cout<<endl;
		cin>>t;
		if(t==1){
			cin>>l>>r;l--;r--;cout<<bit.sum(l,r)<<endl;
		}
		if(t==2){
			cin>>l>>r>>x;l--;r--;
			while(1){
				pint p=query(l,r+1);
				if(p.fi<x) break;
				a[p.se]=p.fi%x;
				bit.add(p.se,p.fi%x-p.fi);
				update(p.se,mp(p.fi%x,p.se));
			}
		}
		if(t==3){
			cin>>l>>x;l--;
			bit.add(l,x-a[l]);
			a[l]=x;
			update(l,mp(a[l],l));
		}
	}
}