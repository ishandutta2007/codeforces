#include <cstdio>
#include <iostream>
using namespace std;
int work_1(long long n){
	while(n>=10){
		n/=10;
	}
	return n;
}
int work_2(long long n){
	int ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int main(){
	long long n;
	cin>>n;
	long long a,b;
	a=work_1(n)-1;
	long long m=n;
	while(m){
		a=a*10+9;
		m/=10;
	}
	a/=10;
	b=n-a;
	printf("%d\n",work_2(a)+work_2(b));
	return 0;
}