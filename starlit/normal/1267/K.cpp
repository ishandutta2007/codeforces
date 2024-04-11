#include<bits/stdc++.h>
using namespace std;
int T,a[60],t,m,b[30];
long long n,ans,c[30][30];
inline void cal(int x){
	if(!b[x])return;
	b[x]--;
	long long now=1;
	int sv=0;
	for(int i=m-2;~i;i--){
		now*=c[sv][b[i]];
		//cerr<<"*C("<<sv<<","<<b[i]<<")\n";
		sv-=b[i];
		if(i>1)sv++;
	}
	b[x]++;ans+=now;
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld",&n);
		for(int i=0;i<30;i++){
			b[i]=0,c[i][0]=1;
			for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
		t=ans=0;
		for(m=2;n;m++)
		a[t++]=n%m,n/=m;
		for(int i=0;i<t;i++)
		//cerr<<a[i]<<' ',
		b[a[i]]++;
		//cerr<<endl;
		for(int i=1;i<m;i++)
		cal(i);
		printf("%lld\n",ans-1);
	}
}