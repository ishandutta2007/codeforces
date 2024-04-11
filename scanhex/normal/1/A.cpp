#include <stdio.h>
#define ll long long

using namespace std;

int main() 
{
	ll a, b, c;
	scanf("%I64d %I64d %I64d", &a, &b, &c);
	printf("%I64d", (a + c - 1) / c * ((b + c - 1) / c));
}