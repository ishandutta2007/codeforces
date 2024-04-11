#include<bits/stdc++.h>



using namespace std;

typedef long long INT;

INT pow(int n){

	if(n==0) return 1;

	INT ans=1;

	for(int i=1;i<=n;i++)

	ans*=2;

	return ans;

}



int nl[100],nr[100];



int main(){

	INT l,r,ans=0;

	int len1=0,len2=0;

	scanf("%I64d%I64d",&l,&r);

	if(l==r) {	printf("0"); return 0; }

	while(l!=0){

		nl[len1++]=l%2;

		l/=2;

	}

	

	while(r!=0){

		nr[len2++]=r%2;

		r/=2;

	}

	

	if(len2>len1) {

		ans=pow(len2)-1;

		printf("%I64d",ans);

		return 0;	

	}

	

	for(int i=len1-1;i>=0;i--)

		if(nr[i]!=nl[i]) {ans=pow(i+1)-1; break;}

	

	

	printf("%I64d",ans);

	return 0;

}