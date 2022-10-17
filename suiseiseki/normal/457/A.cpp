#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
string s;
int i,j,n,x[111111],y[111111];
void I(int *t){
	cin>>s;
	n=s.length();
	for(i=n-1;i+1;i--){
		t[i]=s[n-i-1]-48;
		for(j=i; t[j]&&t[j+1]; j+=2)t[j]=t[j+1]=0,t[j+2]=1;
	}
}
char A(){
	I(x),I(y);
	for(i=100001;i>=0;i--){
		if(x[i]>y[i]){
			return '>';
		}
		if(x[i]<y[i]){
			return '<';
		}
	}
	return'=';
}
int main(){
	putchar(A());
	return 0;
}