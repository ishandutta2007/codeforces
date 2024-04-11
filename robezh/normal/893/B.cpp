#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int n;

int main(){
	int k;
	int maxRes = 1;

	scanf("%d", &n);
	for(int k = 1; k < 15; k++){
		int divi = ((2 << k) - 1) * (2 << (k - 1));
		//cout << divi;
		//if(n % divi != 0) return !printf("%d", maxRes);
		if(n % divi == 0) maxRes = divi;
	}
	cout << maxRes;
	
	//return !printf("%d", maxOdd * maxEven);
	
}