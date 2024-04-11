#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

long long gcd(long long num1, long long num2)//greatest common divisor
{
	if(num1 == 0)
		return num2;
	if(num2 == 0)
		return num1;
	if(num1<0)
		return gcd(-num1, num2);
	if(num2<0)
		return gcd(num1, -num2);
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
	int h, i, j, k;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		char input[n+1];
		int s[n+1];
		int count[n+1][2];
		int find[n+1][2];
		int answer[n+1];
		scanf("%s", input);
		for(i=0; i<n; i++) {
			if(input[i] == 'D') {
				s[i] = 0;
			} else {
				s[i] = 1;
			}
		}
		count[0][0] = 0;
		count[0][1] = 0;
		for(i=1; i<=n; i++) {
			for(j=0; j<2; j++) {
				find[i][j] = -1;
			}
		}
		find[0][0] = 0;
		find[0][1] = 0;
		for(i=1; i<=n; i++) {
			count[i][0] = count[i-1][0];
			count[i][1] = count[i-1][1];
			count[i][s[i-1]]++;
			find[count[i][s[i-1]]][s[i-1]] = i;
		}
		memset(answer, 0, sizeof(answer));
		for(i=1; i<=n; i++) {
			if(answer[i] == 0) {
				int piece = 0;
				int g = gcd(count[i][0], count[i][1]);
				int base[2];
				for(j=0; j<2; j++) {
					base[j] = count[i][j]/g;
				}
				for(j=g; ; j++) {
					int f[2];
					if(base[0]*j > n || base[1]*j > n) {
						break;
					}
					for(k=0; k<2; k++) {
						f[k] = find[base[k]*j][k];
					}
					if(f[0] == -1 || f[1] == -1) {
						break;
					}
					int idx = std::max(f[0], f[1]);
					if(count[idx][0] == base[0]*j && count[idx][1] == base[1]*j) {
						piece++;
						answer[idx] = std::max(answer[idx], piece);
					}
				}
			}
		}
		for(i=1; i<=n; i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}