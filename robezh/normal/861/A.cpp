#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	long long a,n;
	long long tmp;
	
	cin>>a>>n;
	
	int count2 = 0, count5 = 0;
	int numof2 = 0, numof5 = 0;
	tmp = a;
	while(tmp % 2 == 0 && tmp > 0){
		tmp /= 2;
		count2++;
	}
	tmp = a;
	while(tmp % 5 == 0 && tmp > 0){
		tmp /= 5;
		count5++;
	}
	numof2 = count2 >= n ? 0 : n - count2;
	numof5 = count5 >= n ? 0 : n - count5;
	for(int i = 0; i < numof2; i++){
		a *= 2;
	}
	for(int i = 0; i < numof5; i++){
		a *= 5;
	}
	cout<<a;
}