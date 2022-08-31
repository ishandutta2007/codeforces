#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
db res=0;char Na[9];
inline double Pow(db a,int b){
	db c=1;
	for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
	return c;
}
int main(){
	scanf("%s",Na+1);
	if(Na[1]=='B'){
		int n;scanf("%d",&n);printf("%d\n",n);return 0;
	}
	else{
		int n,h;scanf("%d%d",&n,&h);
		res=n;
		rep(i,1,h)rep(j,1,n){
			db po=n-j;
			po*=1./Pow(2.,2*i);
			po*=Pow(1-(1./Pow(2,i)),j-1);
			db p2=Pow(2,i);
			p2-=Pow(2,i-1)*(1+(j-1)/(Pow(2,i)-1));
			po*=p2;
			res+=po;
		}
	}
	printf("%.20lf\n",res);
	return 0;
}