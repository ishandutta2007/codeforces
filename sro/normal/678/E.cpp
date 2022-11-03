#include <bits/stdc++.h>
using namespace std;
#define lf long double
#define loop(i,n) for(int i=0;i<(n);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define Mask(a) (1ll<<(a))
#define Full(a) ((1ll<<(a))-1)
#define Bit(a,x) (((a)>>(x))&1)
template<typename _T>
inline _T chmax(_T &a,_T b){return a<b?(a=b):a;}

lf dp[Mask(18)+5][20];
lf p[20][20];
int n;

int main(){
	cin>>n;
	loop(i,n){
		loop(j,n){
			cin>>p[i][j];
		}
	}
	dp[1][0]=1;
	range(i,3,Full(n),2){
		loop(j,n){
			if(Bit(i,j)){
				loop(k,n){
					if(j!=k&&Bit(i,k)){
						chmax(dp[i][j],dp[i^Mask(j)][k]*p[k][j]+dp[i^Mask(k)][j]*p[j][k]);
					}
				}
			}
		}
	}
	lf ans=0;
	loop(i,n){
		chmax(ans,dp[Full(n)][i]);
	}
	cout<<ans<<endl;
	return 0;
}