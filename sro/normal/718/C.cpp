//Go to http://threebody.com/ to learn more about THREEBODY.
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define SZ(s) ((int)(s).size())
#define INT long long
#define Mod 1000000007
#define Inf 0x3f3f3f3f
#define SHENBEN "shurongwang"
using namespace std;
//Coded by charlieyan, all rights reserved.
/*                                               
  mmmm                       mmmm     mmm   mmmm 
 m"  "m  m mm  mmmmm         #   "m     #  m"  "m
 #    #  #"  "    m"         #    #     #  #    #
 #    #  #      m"           #    #     #  #    #
  #mm#   #     #mmmm         #mmm"  "mmm"   #mm#"
                                               # 
*/

struct FibMat{
	bool hv;
	INT Mat[2][2];
	FibMat(){
		Mat[0][0]=0;
		Mat[0][1]=0;
		Mat[1][0]=0;
		Mat[1][1]=0;
	}
	FibMat(int a,int b,int c,int d){
		Mat[0][0]=a;
		Mat[0][1]=b;
		Mat[1][0]=c;
		Mat[1][1]=d;
	}
	FibMat operator*(const FibMat& mat){
		FibMat mat2;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					mat2.Mat[i][k]+=Mat[i][j]*mat.Mat[j][k];
					mat2.Mat[i][k]%=Mod;
				}
			}
		}
		return mat2;
	}
	FibMat operator+(const FibMat& mat){
		FibMat mat2;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				mat2.Mat[i][j]=Mat[i][j]+mat.Mat[i][j];
				if(mat2.Mat[i][j]>=Mod){
					mat2.Mat[i][j]-=Mod;
				}
			}
		}
		return mat2;
	}
};
//Yah See La Liang Fay Fan

struct SegTree{
	FibMat dt[1600005],wp[1600005];
	void Churn(int now,int nl,int nr,int l,int r,FibMat& x){
		wp[now<<1]=wp[now]*wp[now<<1];
		wp[now<<1|1]=wp[now]*wp[now<<1|1];
		dt[now<<1]=wp[now]*dt[now<<1];
		dt[now<<1|1]=wp[now]*dt[now<<1|1];
		wp[now]=FibMat(1,0,0,1);
		if(nl>=l&&nr<=r){
			dt[now]=x*dt[now];
			wp[now]=x*wp[now];
			return;
		}
		if(nr<l||nl>r){
			return;
		}
		int m=(nl+nr)>>1;
		Churn(now<<1,nl,m,l,r,x);
		Churn(now<<1|1,m+1,nr,l,r,x);
		dt[now]=dt[now<<1]+dt[now<<1|1];
	}
	INT sum(int now,int nl,int nr,int l,int r){
		wp[now<<1]=wp[now]*wp[now<<1];
		wp[now<<1|1]=wp[now]*wp[now<<1|1];
		dt[now<<1]=wp[now]*dt[now<<1];
		dt[now<<1|1]=wp[now]*dt[now<<1|1];
		wp[now]=FibMat(1,0,0,1);
		if(nl>=l&&nr<=r){
			return dt[now].Mat[1][0];
		}
		if(nr<l||nl>r){
			return 0;
		}
		int m=(nl+nr)>>1;
		return (sum(now<<1,nl,m,l,r)+sum(now<<1|1,m+1,nr,l,r))%Mod;
	}
	void change(int now,int nl,int nr,int to,const FibMat& x){
		wp[now<<1]=wp[now]*wp[now<<1];
		wp[now<<1|1]=wp[now]*wp[now<<1|1];
		dt[now<<1]=wp[now]*dt[now<<1];
		dt[now<<1|1]=wp[now]*dt[now<<1|1];
		wp[now]=FibMat(1,0,0,1);
		if(nl==to&&nr==to){
			dt[now]=x;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			change(now<<1,nl,m,to,x);
		}else{
			change(now<<1|1,m+1,nr,to,x);
		}
		dt[now]=(dt[now<<1]+dt[now<<1|1]);
	}
}seg;

int n,m;

FibMat ksmii(const FibMat& mat,int x){
	if(!x){
		return FibMat(1,0,0,1);
	}
	FibMat fau=ksmii(mat,x/2);
	fau=fau*fau;
	if(x%2){
		fau=fau*mat;
	}
	return fau;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int ai;
		scanf("%d",&ai);
		seg.change(1,1,n,i,ksmii(FibMat(1,1,1,0),ai)*FibMat(1,0,0,0));
	}
	while(m--){
		int M0DE;
		scanf("%d",&M0DE);
		if(M0DE==1){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			FibMat fau=ksmii(FibMat(1,1,1,0),c);
			seg.Churn(1,1,n,a,b,fau);
		}else{
			int a,b;
			scanf("%d%d",&a,&b);
			#ifdef ORZDALAO
			printf("%lld\n",seg.sum(1,1,n,a,b));
			#else
			printf("%I64d\n",seg.sum(1,1,n,a,b));
			#endif
		}
	}
	return 0;
}