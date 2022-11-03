#include<bits/stdc++.h>
using namespace std;

int n;
long long k;
int main(){
	scanf("%d%I64d",&n,&k);
	if(k>1ll*n*(n-1)/2){
		printf("Impossible\n");
		return 0;
	}
	int m=0;
	for(;k>=m;m++)k-=m;
	if(k){
		for(int i=0;i<k;i++)printf("(");printf("()");
		for(int i=k;i<m;i++)printf("(");
		for(int i=0;i<m;i++)printf(")");
		for(int i=m+1;i<n;i++)printf("()");
	}else{
		for(int i=0;i<m;i++)printf("(");
		for(int i=0;i<m;i++)printf(")");
		for(int i=m;i<n;i++)printf("()");
	}
	return 0;
}