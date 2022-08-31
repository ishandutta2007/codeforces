#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<deque>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
const int S=600;
int n,q;
inline int Mi(const int &a,const int &b){if(a<b)return a;return b;}
inline int bel(const int &x){return (x-1)/S;}
inline int beg(const int &x){return x*S+1;}
inline int ed(const int &x){return Mi((x+1)*S,n);}
struct kuai{
	deque<int>Q;
	int cnt[N];
	inline void jin(int &x){cnt[x]++;Q.push_back(x);}
	inline void jinf(int &x){cnt[x]++;Q.push_front(x);}
	inline int outFront(){int x=Q.front();Q.pop_front();cnt[x]--;return x;}
	inline int outBack(){int x=Q.back();Q.pop_back();cnt[x]--;return x;}
	
	inline void outit(){
		rep(i,0,n-1)printf("%d ",Q[i]);printf("\n");
	}
}Every[S];
vector<int>a,b,c;
inline void Rotate(int l,int r){
	if(l==r)return;
	a.clear();b.clear();c.clear();
	int xx=bel(l);int yy=bel(r);
	if(xx==yy){
		for(int i=beg(xx);i<=l-1;i++)a.push_back(Every[xx].outFront());
		
		for(int i=l;i<=r;i++)b.push_back(Every[xx].outFront());
		
		for(int i=r+1;i<=ed(xx);i++)c.push_back(Every[xx].outFront());
		
		for(int i=0;i<a.size();i++)Every[xx].jin(a[i]);
		
		Every[xx].jin(b[b.size()-1]);
		b.pop_back();
		
		for(int i=0;i<b.size();i++)Every[xx].jin(b[i]);
		
		for(int i=0;i<c.size();i++)Every[xx].jin(c[i]);
	}
	else{
		int last=Every[xx].outBack();
		
		for(int i=l;i<ed(xx);i++)a.pb(Every[xx].outBack());
		
		for(int i=xx+1;i<yy;i++){
			Every[i].jinf(last);
			last=Every[i].outBack();
		}
		
		for(int i=beg(yy);i<r;i++)b.pb(Every[yy].outFront());
		
		int Guan=Every[yy].outFront();
		
		for(int i=(int)b.size()-1;i>=0;i--)Every[yy].jinf(b[i]);
		
		Every[yy].jinf(last);
		
		Every[xx].jin(Guan);
		
		for(int i=(int)a.size()-1;i>=0;i--)Every[xx].jin(a[i]);
	}
}
inline int calc(int l,int r,int k){
	int xx=bel(l);int yy=bel(r);
	
	a.clear();b.clear();c.clear();int ans=0;
	
	if(xx==yy){
		for(int i=beg(xx);i<=l-1;i++)a.push_back(Every[xx].outFront());
		
		for(int i=l;i<=r;i++)b.push_back(Every[xx].outFront());
		
		for(int i=r+1;i<=ed(xx);i++)c.push_back(Every[xx].outFront());
		
		for(int i=0;i<b.size();i++)ans+=(b[i]==k);
		
		for(int i=0;i<a.size();i++)Every[xx].jin(a[i]);
		
		for(int i=0;i<b.size();i++)Every[xx].jin(b[i]);
		
		for(int i=0;i<c.size();i++)Every[xx].jin(c[i]);
	}
	else{
		for(int i=xx+1;i<yy;i++)ans+=Every[i].cnt[k];
		
		for(int i=l;i<=ed(xx);i++){
			int xxx=Every[xx].outBack();
			a.pb(xxx);ans+=(xxx==k);
		}
		
		for(int i=(int)a.size()-1;i>=0;i--)Every[xx].jin(a[i]);
		
		for(int i=beg(yy);i<=r;i++){
			int xxx=Every[yy].outFront();
			b.pb(xxx);ans+=(xxx==k);
		}
		
		for(int i=(int)b.size()-1;i>=0;i--)Every[yy].jinf(b[i]);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int v;scanf("%d",&v);Every[bel(i)].jin(v);
	}
	scanf("%d",&q);int lastans=0;
	while(q--){
		//Every[0].outit();
		int opt,l,r,u;
		scanf("%d%d%d",&opt,&l,&r);
		l=(l+lastans-1)%n+1;
		r=(r+lastans-1)%n+1;
		if(l>r)swap(l,r);
		if(opt==1)Rotate(l,r);
		else{
			scanf("%d",&u);
			u=(u+lastans-1)%n+1;
			lastans=calc(l,r,u);
			printf("%d\n",lastans);
		}
	}
	return 0;
}