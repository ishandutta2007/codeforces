#include <cstdio>
#define Maxn 5000
double f[Maxn+5][Maxn+5];
int p[Maxn+5],t[Maxn+5];
/*double ksm(double x,int y){
	double ans=1.0;
	while(y){
		if(y&1){
			ans*=x;
		}
		x*=x;
		y>>=1;
	}
	return ans;
}*/
double ksm(double x,int y){
	double ans=1.0;
	for(int i=0;i<y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	int n,T;
	scanf("%d%d",&n,&T);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i],&t[i]);
	}
	double ans=0.0,pp;
	double r_1,r_2,now;
	f[0][0]=1.0;
	for(int i=0;i<n;i++){
		pp=p[i]/100.0;
		now=0.0;
		r_2=ksm(1-pp,t[i]-1);
		r_1=r_2*pp;
		for(int j=0;j<T;j++){
			now+=(f[i][j]-now)*pp;
			if(j+1>=t[i]){
				now-=f[i][j+1-t[i]]*r_1;
				f[i+1][j+1]+=now+f[i][j+1-t[i]]*r_2;
			}
			else{
				f[i+1][j+1]+=now;
			}
		}
		for(int j=0;j<=T;j++){
			ans+=f[i+1][j];
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}