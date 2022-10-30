#include <bits/stdc++.h>

using namespace std;

int isprime(long long num)
{
	if(num <= 1)
		return 0;
	long long div;
	for(div=2; div*div<=num; div++)
		if(num%div == 0)
			return 0;
	return 1;
}

vector<vector<int>> factorize(int num) {
	vector<vector<int>> answer;
	int div;
	for(div=2; num>1; div++) {
		if(div*div > num) {
			answer.push_back({num, 1});
			break;
		}
		if(num%div == 0) {
			answer.push_back({div, 0});
		}
		while(num%div == 0) {
			answer.back()[1]++;
			num /= div;
		}
	}
	return answer;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int x, d;
		scanf("%d %d", &x, &d);
		if(isprime(d)) {
			int count = 0;
			while(x%d == 0) {
				x /= d;
				count++;
			}
			if(count <= 1 || isprime(x) || x == 1) {
				printf("NO\n");
			} else {
				printf("YES\n");
			}
		} else {
			x /= d;
			if(x%d != 0) {
				printf("NO\n");
			} else {
				x /= d;
				if(isprime(x) || x == 1) {
					printf("NO\n");
				} else {
					vector<vector<int>> facd = factorize(d);
					vector<vector<int>> facx = factorize(x*d*d);
					if(facx.size() == 1 && facd.size() == 1) {
						d = facd[0][1];
						x = facx[0][1];
						int count = 0;
						for(i=2; i<=x/d; i++) {
							if((2*d-1)*i >= x) {
								int diff = x-d*i;
								count += diff;
							}
						}
						if(count > 1) {
							printf("YES\n");
						} else {
							printf("NO\n");
						}
					} else {
						printf("YES\n");
					}
				}
			}
		}
	}
}