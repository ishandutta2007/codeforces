#include<bits/stdc++.h>
using namespace std;
long long rar[100];
long long ar[100];
long long nxt(long long x)
{
	if(x == 0) return 0;
	if(x <= 15)
	{
		long long y = rar[x];
		if(y%3) return ar[y + 1];
		return ar[y - 2];
	}
	long long z = 1;
	while(x >= 4 * z)
	{
		z *= 4;
	}
	long long a = x / z;
	long long b = x % z;
	long long c = a % 3;
	c++; 
	return nxt(b) + c * z;
}
int main()
{
	int ttt;
	ar[1] = 1;
	ar[2] = 2;
	ar[3] = 3;
	ar[4] = 4;
	ar[5] = 8;
	ar[6] = 12;
	ar[7] = 5;
	ar[8] = 10;
	ar[9] = 15;
	ar[10] = 6;
	ar[11] = 11;
	ar[12] = 13;
	ar[13] = 7;
	ar[14] = 9;
	ar[15] = 14;
	for(int i = 1; i <= 15; i++) rar[ar[i]] = i;
	scanf("%d", &ttt);
	long long ct = 0;
	while(ttt--)
	{
		long long x;
		scanf("%lld", &x);
		x--;
		//x = ct++;
		long long y = x / 3;
		long long z = 1;
		while(y >= z)
		{
			y -= z;
			z *= 4;
		}
		y += z;
		//long long zxc = nxt(y);
		if(x % 3 == 0) printf("%lld\n", y);
		else if(x % 3 == 1) printf("%lld\n", nxt(y));	
		else printf("%lld\n", nxt(nxt(y)));
	}
	//printf("done\n");
	return 0;
}