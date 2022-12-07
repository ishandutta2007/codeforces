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
#include<cassert>
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
ostream &operator<<(ostream &os, const vector<int> &a) {
	os<<"[";
	rep(i,a.size()){
		os<<a[i];
		if(i<a.size()-1) os<<",";
	}
	os<<"]";
	return os; 
}
struct wavelet{
	vector<int> sorted;
	vector<int> dat[25];
	vector<int> le[25],ri[25];
	int n;
	void build(int l,int r,int d){
		//from[id]=l;to[id]=r;
		int p=l,md=(l+r)/2,p2=md;
		if(l+1==r) return;
		REP(i,l,r){
			if(dat[d][i]<sorted[md]) dat[d+1][p++]=dat[d][i];
			else dat[d+1][p2++]=dat[d][i];
			le[d][i]=p-l;ri[d][i]=p2-md;
		}
		build(l,md,d+1);build(md,r,d+1);
	}
	wavelet(vector<int> v){
		n=v.size();
		dat[0]=v;
		sorted=v;
		sort(All(sorted));
		rep(i,23) dat[i+1]=vector<int>(n+10,0),le[i]=vector<int>(n+10,0),ri[i]=vector<int>(n+10,0);
		build(0,n,0);
	}
	//()xy
	int num(int x,int y,int d,int l,int r){
		if(x<0 || y<0) return 0;
		int ret;
		if(l+1==r){
			if(dat[d][l]<=y) ret=1;else ret=0;
		}
		else{
			int mi=(l+r)/2;
			if(sorted[mi]<=y) ret=le[d][l+x]+num(x-le[d][l+x],y,d+1,mi,r);
			else ret=num(le[d][l+x]-1,y,d+1,l,mi);
		}
		return ret;
	}
	int num(int x,int y){
		return num(x,y,0,0,n);
	}
};
lint cal[5][5],ca2[5][5];
int main()
{
	vector<int> v;
	int q,a,l,d,u,r,n;
	scanf("%d %d",&n,&q);
	rep(i,n){
		scanf("%d",&a);a--;
		v.pb(a);
	}
	wavelet wav(v);
	//rep(i,3) cout<<dat[i]<<endl<<le[i]<<endl;
	//cout<<num(3,3)<<endl;
	rep(k,q){
		scanf("%d %d %d %d",&l,&d,&r,&u);
		l--;d--;
		vector<int> ta,yo;
		ta.pb(0);ta.pb(l);ta.pb(r);ta.pb(n);
		yo.pb(0);yo.pb(d);yo.pb(u);yo.pb(n);
		rep(i,3) rep(j,3){
			cal[i][j]=wav.num(ta[i+1]-1,yo[j+1]-1);
			ca2[i][j]=cal[i][j];
			if(i>0) ca2[i][j]-=cal[i-1][j];
			if(j>0) ca2[i][j]-=cal[i][j-1];
			if(i>0 && j>0) ca2[i][j]+=cal[i-1][j-1];
		}
		rep(i,3){
			//rep(j,3) cout<<cal[i][j]<<' ';cout<<endl;
		}
		rep(i,3){
			//rep(j,3) cout<<ca2[i][j]<<' ';cout<<endl;
		}
		lint sum=0;
		rep(i,3) rep(j,3) rep(I,3) rep(J,3){
			if((i-1)*(j-1)>0 || (I-1)*(J-1)>0) continue;
			//cout<<i<<' '<<j<<' '<<I<<' '<<J<<endl;
			if(i*j*I*J==1) sum+=ca2[i][I]*(ca2[i][I]-1);
			else sum+=ca2[i][I]*ca2[j][J];
		}
		printf("%I64d\n",sum/2);
	}
}