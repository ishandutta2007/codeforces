#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const int o=3010;const double PI=acos(-1);
int n,R,x[o],y[o],ans;bool a[o][o];double la,ra,k,La,Ra,t;
inline double calc(double v){for(;v>PI;v-=2*PI);for(;v<-PI;v+=2*PI);return v;}
int main(){
	scanf("%d%d",&n,&R);
	for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i){
		la=-PI;ra=PI;
		for(int j=1;j<=n;++j) if(R*1ll*R<(x[i]-x[j])*1ll*(x[i]-x[j])+(y[i]-y[j])*1ll*(y[i]-y[j])){
			k=atan2(y[j]-y[i],x[j]-x[i]);t=R/sqrt((x[i]-x[j])*1ll*(x[i]-x[j])+(y[i]-y[j])*1ll*(y[i]-y[j]));
			if((La=calc(k-asin(t)))>(Ra=calc(k+asin(t)))) swap(La,Ra);
			if(Ra-La>PI) swap(La,Ra),Ra+=2*PI;
			if(la==-PI&&ra==PI){la=La;ra=Ra;continue;}
			if(ra<La) la+=2*PI,ra+=2*PI;
			if(Ra<la) La+=2*PI,Ra+=2*PI;
			la=max(la,La);ra=min(ra,Ra);
			if(la>ra) break;
		}
		if(la<=ra) for(int j=1;j<=n;++j) k=atan2(y[j]-y[i],x[j]-x[i]),a[i][j]=((la<=k&&k<=ra)||(la-2*PI<=k&&k<=ra-2*PI));
	}
	for(int i=1;i<n;++i) for(int j=n;j>i;--j) ans+=(a[i][j]&&a[j][i]);
	printf("%d",ans);
	return 0;
}