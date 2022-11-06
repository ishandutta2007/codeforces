#include<iostream>
#include<algorithm>
#include<cstring>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll MAXN=1000000000000000001LL;
char ANS[201];
ll dp[201][201],ff;
pair<long,long> P[10001];
long n,m,i,j,k,l;
inline void add(ll &X,const ll Y){
	X+=Y;
	if(MAXN<X) X=MAXN;
}
inline bool check(){
	memset(dp,0,sizeof(dp));
	dp[0][1]=1;
	long ii,jj;
	for(ii=1;ii<=n+m-2;++ii){
		if(ANS[ii]!='('){
			for(jj=0;jj<l;++jj)
				add(dp[ii][jj],dp[ii-1][jj+1]);
			}
		if(ANS[ii]!=')'){
			for(jj=1;jj<=l;++jj)
				add(dp[ii][jj],dp[ii-1][jj-1]);
			}
		}
	return dp[n+m-2][0]<ff;
}
int main(){
	ANS[0]='(';
	cin>>n>>m>>ff;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			cin>>k,P[k].x=i,P[k].y=j;
	ANS[n+m-2]=')',l=(n+m-1)/2;
	for(i=1;i<=n*m;++i)
		if(!ANS[P[i].x+P[i].y]){
			ANS[P[i].x+P[i].y]='(';
			if(check()){
				ANS[P[i].x+P[i].y]=')',ff-=dp[n+m-2][0];
				}
			}
	for(i=0;i<n;++i){
		for(j=0;j<m;++j)
			cout<<ANS[i+j];
		cout<<endl;
		}
	cin>>n;
	return 0;
}