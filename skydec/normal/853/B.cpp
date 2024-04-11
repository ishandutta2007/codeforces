#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
struct ft{
	int d,x,w;
}in[N],out[N];
inline bool cmp(const ft &a,const ft &b){
	return a.d<b.d;
}
int n,m,k;
int t1,t2;
multiset<int> f[N];
int res[N];
int res2[N];
LL sum;
bool shan(int x,int w){
	f[x].erase(f[x].find(w));
	if(!f[x].size())return 1;
	sum+=(*f[x].begin())-res[x];
	res[x]=(*f[x].begin());
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b==0){
			++t2;
			out[t2].d=a;
			out[t2].x=c;
			out[t2].w=d;
		}
		else{
			++t1;
			in[t1].d=a;
			in[t1].x=b;
			in[t1].w=d;
		}
	}
	if((!t1)||(!t2)){
		printf("-1\n");
		return 0;
	}
	sort(in+1,in+1+t1,cmp);
	sort(out+1,out+1+t2,cmp);
	rep(i,1,t2)f[out[i].x].insert(out[i].w);
	LL ans=1ll<<60;
	sum=0;
	rep(i,1,n)if(!f[i].size()){
		printf("-1\n");
		return 0;
	}else{
		res[i]=(*f[i].begin());
		sum+=(*f[i].begin());
	}
	rep(i,1,n)res2[i]=1<<30;
	int st=0;
	LL sum2=0;
	int zb=1;
	rep(i,1,t1){
		if(res2[in[i].x]>2000000){
			++st;
			sum2+=in[i].w;
			res2[in[i].x]=in[i].w;
		}
		else{
			if(in[i].w<=res2[in[i].x]){
				sum2+=in[i].w-res2[in[i].x];
				res2[in[i].x]=in[i].w;
			}
		}
		while(zb<=t2&&out[zb].d<=in[i].d+k){
			if(shan(out[zb].x,out[zb].w))goto fin;
			zb++;
		}
		if(st==n)ans=min(ans,sum2+sum);
	}
	fin:;
	if(ans<(1ll<<60))printf("%I64d\n",ans);
	else puts("-1");
	return 0;
}