#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	long long a,b;
	cin>>a>>b;
	int res = 1;
	if(a / 10 < b / 10) res = 0;
	else{
		a %= 10;
		b %= 10;
		for(int i = b; i > a; i--) res *= i;
		res %= 10;
	}
	printf("%d",res);
}