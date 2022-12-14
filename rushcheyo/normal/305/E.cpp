#include<bits/stdc++.h>
using namespace std;
const int N=5005;
char s[N];
int n,v[N],sg[N];
int calc(int l,int r){
	int x=0,lst=0;
	for(int i=l+1;i<r;i++)
		if(s[i-1]==s[i+1])lst++;
		else x^=sg[lst],lst=0;
	return x^=sg[lst];
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	sg[1]=1;
	for(int i=2;i<=n;i++){
		v[sg[i-2]]=i;
		for(int j=2;j<=i-1;j++)
			v[min(sg[j-2]^sg[i-j-1],n+1)]=i;
		int x=0;
		while(v[x]==i)x++;
		sg[i]=x;
	}
	if(calc(1,n)){
		puts("First");
		int k;
		for(k=2;k<n;k++)
			if(s[k-1]==s[k+1]&&(calc(1,k-1)^calc(k+1,n))==0){
				printf("%d\n",k);
				return 0;
			}
	}else puts("Second");
	return 0;
}