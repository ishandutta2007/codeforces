#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=55;
char s[N];
int n;
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	int ans=0;
	rep(i,n)for(int j=i;j<=n;++j){
		bool flag=1;
		for(int k=1;k<=j-i+1;++k)if(s[i+k-1]!=s[j-k+1]){flag=0;break;}
		if(!flag)ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}