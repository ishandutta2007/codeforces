#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long INT;
using namespace std;

int T[100005];

struct SegTree{
	INT dt1[800005],wp1[800005],dt2[800005];
	void plus1(int now,int nl,int nr,int l,int r){
		if(wp1[now]){
			wp1[now<<1]+=wp1[now];
			wp1[now<<1|1]+=wp1[now];
			dt1[now<<1]+=wp1[now];
			dt1[now<<1|1]+=wp1[now];
			wp1[now]=0;
		}
		if(nl>=l&&nr<=r){
			dt1[now]+=nr-nl+1;
			wp1[now]++;
			return;
		}
		if(nr<l||nl>r){
			return;
		}
		int m=(nl+nr)>>1;
		plus1(now<<1,nl,m,l,r);
		plus1(now<<1|1,m+1,nr,l,r);
		dt1[now]=dt1[now<<1]+dt1[now<<1|1];
	}
	void plus2(int now,int nl,int nr,int to,INT x){
		if(nl==to&&nr==to){
			dt2[now]+=x;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			plus2(now<<1,nl,m,to,x);
		}else{
			plus2(now<<1|1,m+1,nr,to,x);
		}
		dt2[now]=dt2[now<<1]+dt2[now<<1|1];
	}
	INT what(int now,int nl,int nr,int to){
		if(wp1[now]){
			wp1[now<<1]+=wp1[now];
			wp1[now<<1|1]+=wp1[now];
			dt1[now<<1]+=wp1[now];
			dt1[now<<1|1]+=wp1[now];
			wp1[now]=0;
		}
		if(nl==to&&nr==to){
			return T[to]*dt1[now]+dt2[now];
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			return what(now<<1,nl,m,to);
		}else{
			return what(now<<1|1,m+1,nr,to);
		}
	}
}seg;

int n;
int V[100005];
INT qzh[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",V+i);
	}
	for(int j=1;j<=n;j++){
		scanf("%d",T+j);
		qzh[j]=qzh[j-1]+T[j];
	}
	for(int i=1;i<=n;i++){
		int fff=lower_bound(qzh,qzh+n+1,V[i]+qzh[i-1])-qzh;
		if(fff>i){
			seg.plus1(1,1,n,i,fff-1);
		}
		if(fff>=i&&fff!=n+1){
			seg.plus2(1,1,n,fff,V[i]+qzh[i-1]-qzh[fff-1]);
			//cerr<<qzh[fff]<<' '<<V[i]<<' '<<qzh[i-1]<<' '<<i<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		#ifdef XUDADIAO
		printf("%lld%c",seg.what(1,1,n,i),i==n?'\n':' ');
		#else
		printf("%I64d%c",seg.what(1,1,n,i),i==n?'\n':' ');
		#endif
	}
	return 0;
}
//WUT? 100005*16+400005*24 can MLE?