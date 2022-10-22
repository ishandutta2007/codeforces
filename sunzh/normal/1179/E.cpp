#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,L;
PII ans[1010];
int pos;
map<PII,int>Map;
vector<int>ls,rs;
int query(int p,int x){
	if(Map.count(mp(p,x))) return Map[mp(p,x)];
	printf("? %lld %lld\n",p,x);fflush(stdout);
	return Map[mp(p,x)]=read();
}
void findkth(vector<int>ve,int val,int xl,int xr,int sz){
	int p=ve[rand()%ve.size()];
	int l=xl,r=xr,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		int t=query(p,mid);
		if(t<val) l=mid+1;
		else if(t==val) {
			res=mid;break ;
		}
		else if(t>val) r=mid-1;
	}
	vector<int>v1,v2,tmp;
	for(int i:ve){
		int t=query(i,res);
		if(t>val) v1.pb(i);
		else if(t<val)v2.pb(i);
		else tmp.pb(i);
	}
	while(tmp.size()&&v1.size()<sz){
		v1.pb(tmp.back());tmp.pop_back();
	}
	while(tmp.size()){
		v2.pb(tmp.back());
		tmp.pop_back();
	}
	if(v1.size()==sz){
		pos=res;
		for(int i:v1) ls.pb(i);
		for(int i:v2) rs.pb(i);
		return ;
	}
	if(v1.size()<=sz){
		for(int i:v1) ls.pb(i);
		findkth(v2,val,res,xr,sz-v1.size());
	}
	else{
		for(int i:v2) rs.pb(i);
		findkth(v1,val,xl,res,sz);
	}
}
void solve(vector<int>ve,int vl,int vr,int xl,int xr){
	if(ve.size()==1){
		ans[ve[0]]=mp(xl,xr);
	 	return ;
	}
	int sz=(ve.size()>>1);
	int mid=vl+(L/n)*sz;
	pos=-1;vector<int>().swap(ls);vector<int>().swap(rs);
	findkth(ve,mid,xl,xr,sz);
	vector<int>R=rs;
	int rp=pos;
	solve(ls,vl,mid,xl,pos);
	solve(R,mid,vr,rp,xr);
}
signed main(){
	srand(time(0));
	n=read(),L=read();
	vector<int>all;
	for(int i=1;i<=n;++i) all.pb(i);
	solve(all,0,L,0,1e18);
	printf("!\n");
	for(int i=1;i<=n;++i) printf("%lld %lld\n",ans[i].fi,ans[i].se);
}