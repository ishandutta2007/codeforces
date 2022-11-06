#include<stdio.h>
#include<iostream>
#include<algorithm>

int n,m;

char s[200001];

int nxtlength[200001];

long long ans;

int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=n;i;--i){
		if(s[i]==s[i+2]) nxtlength[i]=nxtlength[i+2]+2;
		else nxtlength[i]=0;
	}
	for(int i=1;i<n;++i){
		if(s[i]!=s[i+1]){
			ans+=(n-i)*(m-1);
		}
	}
	for(int i=n;i>1;--i){
		if(s[i]!=s[i-1]){
			ans+=(i-1)*(m-1);
		}
	}
	for(int i=1;i<n;++i) if(s[i]!=s[i+1]){
		int end=std::min(i+nxtlength[i],i+1+nxtlength[i+1]);
		++end;
		ans-=end-i;
	}
	std::cout<<ans + n * (m - 1)<<std::endl;
	return 0;
}