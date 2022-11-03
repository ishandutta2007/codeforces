#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<(n);i++)

const int jt=1000000007;

template<int R,int C=R>
struct matrix{
	int mat[R][C];
	int* operator[](int x){
		return mat[x];
	}
	matrix(){loop(i,R)loop(j,C)mat[i][j]=0;}
	matrix(int x){loop(i,R)loop(j,C)mat[i][j]=(i==j?x:0);}
	matrix<R,C> operator+(const matrix<R,C> m){
		matrix<R,C> ans;
		loop(i,R)loop(j,C)ans.mat[i][j]=(mat[i][j]+m.mat[i][j])%jt;
		return ans;
	}
	template<int D>
	matrix<R,D> operator*(const matrix<C,D> m){
		matrix<R,D> ans;
		loop(i,R)loop(j,C)loop(k,D)ans.mat[i][k]=(ans.mat[i][k]+((long long)mat[i][j])*m.mat[j][k])%jt;
		return ans;
	}
	matrix<R,C> operator+=(const matrix<R,C> m){
		matrix<R,C> ans;
		loop(i,R)loop(j,C)ans.mat[i][j]=(mat[i][j]+m.mat[i][j])%jt;
		return ans;
	}
	matrix<R,C> operator-=(const matrix<R,C> m){
		matrix<R,C> ans;
		loop(i,R)loop(j,C)ans.mat[i][j]=(mat[i][j]-m.mat[i][j]+jt)%jt;
		return ans;
	}
	void debug(){
		loop(i,R){loop(j,C)cerr<<mat[i][j]<<' ';cerr<<endl;}cerr<<endl;
	}
};

template<typename _T>
inline _T qp(_T a,long long b){
	if(!b){return 1;}
	_T x=qp(a,b>>1);x=x*x;
	if(b&1){x=x*a;}return x;
}

int n;
long long k;
long long a[105];
matrix<105> trs;

int main(){
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			long long x=(a[i]^a[j]);
			int res=0;
			while(x){
				if(x&1){
					res++;
				}
				x>>=1;
			}
			if(res%3==0){
				trs[i][j]=1;
			}
		}
	}
	trs=qp(trs,k-1);
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans=(ans+trs[i][j])%jt;
		}
	}
	printf("%d\n",ans);
	return 0;
}