#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int n,a[1005][1005];
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			scanf("%I64d",&a[i][j]);
		}
	int res=a[1][2];
	for(int j=3;j<=n;++j)
		res=gcd(res,a[1][j]);
	//	cout<<"HI "<<res<<endl;
	while(res!=1&&res){
		bool ok=1;
		for(int i=2;i<=n&&ok;++i){
			int Ai=a[1][i]/res;
			for(int j=i+1;j<=n;++j){
				int Aj=a[1][j]/res; 
				if(Ai*Aj!=a[i][j]){
				//	cout<<"shit! "<<Ai*Aj<<" "<<a[i][j]<<endl;
					res/=sqrt(a[i][j]/(Ai*Aj));
					ok=0;
				//	return 0;
					break;
				}
			}
		}
	//	cout<<"HI "<<res<<endl;
		if(ok==1)break;
	}
	printf("%I64d ",res);
	for(int i=2;i<=n;++i)printf("%I64d ",a[1][i]/res);
	return 0;
}