#include<bits/stdc++.h>

#define NN 1000100



using namespace std;

typedef long long INT;

char str[NN];



int main(){

	int len,k=0,m,n;

	INT ans=1;

	

	cin>>str;

	len=strlen(str);

	for(int i=1;i<len;i++){

		m=str[i]-'0';

		n=str[i-1]-'0';

		if(m+n==9) k++;

		else{

			if(k%2==0) ans*=1LL*(k/2+1);

			k=0;

		}

	}

	if(k%2==0) ans*=1LL*(k/2+1);

	printf("%I64d",ans);

	return 0;

}