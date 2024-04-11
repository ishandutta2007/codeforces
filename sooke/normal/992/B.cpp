#include <iostream>
#include <cstdio>

using namespace std;

int Gcd(int x , int y){
	return y == 0 ? x : Gcd(y , x % y);
}

long long l , r , x , y , xy; 

inline long long Solve(int d){
	int cnt = 0 , i;
	for(i = (l - 1) / x + 1 ; i * i <= d && x * i <= r ; i++)
		if(d % i == 0 & l <= d / i * x && d / i * x <= r && Gcd(i , d / i) == 1)
			cnt += 2;
	i--;
	if(i * i == d && l <= i * x && i * x <= r && Gcd(i , d / i) == 1)
		cnt--;
	return cnt;
}

int main(){
	cin >> l >> r >> x >> y;
	if(y % x != 0){
		printf("0\n");
		return 0;
	}
	printf("%d\n" , Solve(y / x));
	return 0;
}

// By Sooke.
// CF992B Nastya Studies Informatics.