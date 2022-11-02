#include<bits/stdc++.h>

using namespace std;

char str[350][350];



int main(){

	int n;

	cin>>n;

	for(int i=0;i<n;i++) scanf("%s",str[i]);

	char c=str[0][0],cc=str[0][1];

	if(c==cc) { puts("NO"); return 0; } 

	for(int i=0;i<n;i++)

	for(int j=0;j<n;j++){

		if((i==j || j==n-i-1) && str[i][j]!=c) { puts("NO"); return 0; }

		if( i!=j && j!=n-i-1 && str[i][j]!=cc) { puts("NO"); return 0;}

	}

	puts("YES");

	return 0;

}