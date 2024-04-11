#include<bits/stdc++.h>
using namespace std;
char ch[155];
int n,a[155],b[155],now,ans;
int main(){
	scanf("%d%s",&n,ch+1);
	for(int i=1;i<=n;++i){
		ch[i]-=48;
		now+=ch[i];
		scanf("%d%d",&a[i],&b[i]);
	}
//	cout<<"OK "<<endl;
ans=max(ans,now);
	for(int i=1;i<=10000;++i){
		//cout<<"HI "<<i<<endl;
		for(int j=1;j<=n;++j){
			if(i>=b[j]&&(i-b[j])%a[j]==0){
				now-=ch[j];
				ch[j]^=1;
				now+=ch[j];
			}
		}
		ans=max(ans,now);
	}
	printf("%d",ans);
	return 0;
}