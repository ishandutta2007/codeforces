#include <bits/stdc++.h> 
using namespace std;
long long a , x; 
int main()
{
	scanf("%lld" , &a);
	x = (long long)pow(10 , 18) % a * 9 % a * 9 % a;
	printf("%lld %lld" , a - x , (long long)pow(10 , 18) - 1 + a - x);
	return 0;
}
/*

*/