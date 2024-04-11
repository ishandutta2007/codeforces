#include<bits/stdc++.h>
const int N=103,V=10005;
using namespace std;
int n,m,a[N],f[N][V],ti=1,ma,qwq,ans;
int main(){
	scanf("%d",&n);f[0][0]=1;
	for(int i=0;i<n;i++)
	scanf("%d",a+i),m+=a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		//cerr<<i<<"======\n";
		if(a[i]!=a[i+1]){
			for(int j=i+1;j;j--)
			for(int k=a[i];k<=m;k++){
				for(ma=1;ma<=ti&&ma*a[i]<=k&&ma<=j;ma++)
				if(f[j-ma][k-ma*a[i]]){
					if(f[j-ma][k-ma*a[i]]>1||f[j][k])
					f[j][k]=2;
					else f[j][k]=1;
				}
				//if(f[j][k])
				//cerr<<j<<','<<k<<':'<<f[j][k]<<endl;
			}
			ti=0,qwq++;
		}
		ti++;
	}
	if(qwq<3)return printf("%d",n),0;
	ti=0;
	for(int i=0;i<n;i++){
		if(i&&a[i]!=a[i-1])ti=0;
		ti++;ma=ti*a[i];
		if(f[ti][ma]==1)ans=max(ans,ti);
	}printf("%d",ans);
}