#include <bits/stdc++.h>

//http://codeforces.com/contest/672/problem/A

using namespace std;


typedef long long LL;

typedef pair<int,int> pi;

int main()
{
	int n;
	cin >> n;
	// for each length L, we have 9*(10^L-1) numbers of that length L
	// 9*1 numbers of length 1 (1..9)
	// 9*10 numbers of length 2 (10..99)
	// 9*100 numbers of length 3 (100..999)
	// algorithm: find which run of numbers of length L the n'th digit is in
	// then within that run, find which number has the n'th digit
	// convert that number to decimal and take the right digit
	int L = 1;
	int p10 = 1;
	while (n > 9*p10*L)
	{
		n -= 9*p10*L;
		L++;
		p10 *= 10;
	}
	n--;
	int k = n/L;
	int num = p10+k;
	char buf[100];
	sprintf(buf, "%d", num);
	cout << buf[n%L] << endl;
	exit(0);
}