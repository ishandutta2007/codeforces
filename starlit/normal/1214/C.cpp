#include<bits/stdc++.h>
const int N=200005;
using namespace std;
int n,a[N];
char S[N];
int main(){
	scanf("%d%s",&n,S+1);
	for(int i=1;i<=n;i++){
		if(S[i]=='('){
			a[i]=a[i-1]+1;
		}
		else{
			a[i]=a[i-1]-1;
			if(a[i]<-1)return puts("No"),0;
		}
	}
	if(a[n])return puts("No"),0;
	puts("Yes");
}