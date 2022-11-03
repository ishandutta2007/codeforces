#include<bits/stdc++.h>
using namespace std;

int n,a[10];
char s[10];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int i=0;i<7;i++)if(s[i]=='1')a[i]++;
	}
	int ans=0;
	for(int i=0;i<7;i++)if(ans<a[i])ans=a[i];
	printf("%d\n",ans);
	return 0;
}