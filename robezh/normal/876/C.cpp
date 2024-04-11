#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int getDigitSum(int num){
	int sum = 0;
	while(num > 0){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

vector<int> V;

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = max(0,n - 90); i < n; i++){
		if(getDigitSum(i) + i == n){
			V.push_back(i);
		}
	}
	cout<<V.size()<<endl;
	for(int i = 0; i < V.size(); i++){
		printf("%d ", V[i]);
	}
}