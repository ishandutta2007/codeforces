#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;
int a[5010];
int pos[5010];
int cnt;
vector<PII>opt;
vector<int>ans;
int Merge(int x,int y){
//	printf("x:%d,y:%d\n",x,y);
	if(!x) return y;
	if(!y) return x;
	opt.pb(mp(x,y));
	++cnt;
	return  cnt;
}
struct BLock{
	vector<vector<int> >num;
	vector<int>ps;
	int query(int l,int r)const{
		if(r<ps.front()||l>ps.back()) return 0;
		if(l>r) return 0;
		int L=lower_bound(ps.begin(),ps.end(),l)-ps.begin();
		int R=upper_bound(ps.begin(),ps.end(),r)-ps.begin()-1;
//		printf("l:%d,r:%d,L:%d,R:%d\n",l,r,L,R);
		if(L>R) return 0;
		return num[L][R-L];
	}
	BLock(int x=0){
		num.resize(2);
		num[0].resize(2);
		if(!x) return ;
		ps.pb(pos[x]);
		num[0][0]=pos[x];
	}
	BLock init(BLock x,BLock y){
		ps.resize(x.ps.size()+y.ps.size());
		merge(x.ps.begin(),x.ps.end(),y.ps.begin(),y.ps.end(),ps.begin());
//		sort(ps.begin(),ps.end());
		num.resize(ps.size()+2);
//		printf("%d\n",ps.size());
		for(int i=0;i<ps.size();++i) num[i].resize(ps.size()-i+2);
		for(int i=0;i<ps.size();++i){
			for(int j=i;j<ps.size();++j){
				num[i][j-i]=Merge(x.query(ps[i],ps[j]),y.query(ps[i],ps[j]));
			}
		}
		return *this;
	}
}blocK[2010];
int Num;
BLock solve(int l,int r){
	if(l==r) return(l);
	int mid=l+r>>1;BLock res;
	return res.init(solve(l,mid),solve(mid+1,r));
}
int main(){
	n=read(),q=read();cnt=n;
	int siz=sqrt(max(q,n));
	for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;
	for(int i=1;i<=n;i+=siz){
		int j=min(n,i+siz-1);
		++Num;
		blocK[Num]=solve(i,j);
	}
	while(q--){
		int l=read(),r=read();
		if(l>r) {
			printf("fuck");return 0;
		}
		int res=0;
		for(int i=1;i<=Num;++i){
			res=Merge(res,blocK[i].query(l,r));
		}
		ans.pb(res);
	}
	printf("%d\n",cnt);
	for(auto i:opt) printf("%d %d\n",i.fi,i.se);
	for(auto i:ans) printf("%d ",i);
	return 0;
}