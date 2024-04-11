#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int main(){
    scanf("%d%d",&n,&m);
	if(m==1)swap(n,m);
	if(n==2&&m==2||n==1&&m<4)
	ans=0;
	else{
		if(n==1){
			if(m%6<4)ans=m/6*6;
			else ans=m/6*6+(m%6-3)*2;
		}
		else{
			if(m==2)swap(n,m);
			if(n==2){
					ans=1ll*n*m;
					if(m==3||m==7)ans-=2;
			}
			else{
				ans=1ll*n*m-(n%2==1&&m%2==1);
			}
		}
	}
	printf("%lld",ans);
}