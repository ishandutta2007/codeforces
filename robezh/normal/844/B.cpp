#include<cstdio>
#include<iostream>
using namespace std;

int m,n;
int num[55][55];

long long getPow(int a, int n){
	long long result = 1;
	for(int i = 0; i < n; i++){
		result *= a;
	}
	return result;
} 

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &num[i][j]);
		}
	}
	int countOfWhite = 0, countOfBlack = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		countOfWhite = 0;
		countOfBlack = 0;
		for(int j = 0; j < m; j++){
			if(num[i][j] == 0) countOfWhite++;
			else countOfBlack++;
		}
		sum += getPow(2,countOfWhite) - 1;
		sum += getPow(2,countOfBlack) - 1;
	}
	for(int i = 0; i < m; i++){
		countOfWhite = 0;
		countOfBlack = 0;
		for(int j = 0; j < n; j++){
			if(num[j][i] == 0) countOfWhite++;
			else countOfBlack++;
		}
		sum += getPow(2,countOfWhite) - 1;
		sum += getPow(2,countOfBlack) - 1;
	}
	sum -= n*m;
	cout << sum;
	
}