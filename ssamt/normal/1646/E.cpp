#include <bits/stdc++.h>

using namespace std;

long long gcd(long long num1, long long num2)//greatest common divisor
{
	if(num1<0)
		return gcd(-num1, num2);
	if(num2<0)
		return gcd(num1, -num2);
	if(num1 == 0)
		return num2;
	if(num2 == 0)
		return num1;
	while(num1%num2!=0 && num2%num1!=0)
	{
		if(num1>num2)
			num1 %= num2;
		else
			num2 %= num1;
	}
	return (num1<num2)?num1:num2;
}

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d %d", &n, &m);
	vector<int> s{0};
	for(i=1; i<=20; i++) {
		int get = 0;
		for(j=1; j<(1<<i); j++) {
			int first = -1;
			long long mul = 1;
			int count = 0;
			for(k=0; k<i; k++) {
				if(j&(1<<k)) {
					if(first == -1) {
						first = k;
					}
					mul = mul*(k+1)/gcd(mul, k+1);
					count++;
				}
			}
			if(count%2 == 1) {
				get += (m*(first+1))/mul;
			} else {
				get -= (m*(first+1))/mul;
			}
		}
		s.push_back(get);
		//printf("%d\n", get);
	}
	long long answer = 1;
	int power[n+1] = {};
	for(i=2; i<=n; i++) {
		if(!power[i]) {
			int count = 0;
			for(j=i; j<=n; j*=i) {
				power[j] = 1;
				count++;
			}
			answer += s[count];
		}
	}
	printf("%lld\n", answer);
}