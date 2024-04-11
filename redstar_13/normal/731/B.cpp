#include<bits/stdc++.h>

#define NN 200200



using namespace std;

typedef long long INT;

int a[NN];

INT sum[NN];



int main(){

	int n,len=1;

	cin>>n;

	for(int i=1;i<=n;i++)  scanf("%d",a+i); 

	for(int i=1;i<=n;i++) {

	 	if(a[i]==0) len++;

	 	else sum[len]+=a[i];	 

	}

	

	for(int i=1;i<=len;i++){

		if(sum[i]%2) { puts("NO"); return 0; }

	}

	puts("YES");

	return 0;

}