#include <iostream>
#include <vector>

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
			a[j].push_back(i);
		}
};

int pow_mod(int a, int k, int mod) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2, mod);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

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

int gcd_arr(int* a, int n) {
	int answer = a[0];
	for(int i=1; i<n; i++) {
		answer = gcd(answer, a[i]);
	}
	return answer;
}

int main() {
	int h, i, j;
	int t, n, k;
	int u, v;
	int s, e;
	int mod = 998244353;
	std::cin >> t;
	for(h=0; h<t; h++) {
		std::cin >> n;
		AdjGraph g(n);
		int count[n];
		int left[n];
		int queue[n];
		int removed[n];
		for(i=1; i<n; i++) {
			std::cin >> u >> v;
			g.add(u-1, v-1);
		}
		int answer[n+1];
		for(i=0; i<=n; i++) {
			answer[i] = 0;
		}
		int sum = 0;
		for(k=2; k<n; k++) {
			if((n-1)%k == 0) {
				for(i=0; i<n; i++) {
					count[i] = 0;
					left[i] = g.a[i].size();
					removed[i] = 0;
				}
				s = 0;
				e = 0;
				for(i=0; i<n; i++) {
					if(left[i] == 1) {
						queue[e] = i;
						e++;
					}
				}
				while(s < e) {
					removed[queue[s]] = 1;
					for(i=0; i<g.a[queue[s]].size(); i++) {
						int near = g.a[queue[s]][i];
						if(!removed[near]) {
							if(count[queue[s]]%k == 0) {
								count[near]++;
							}
							left[near]--;
							if(left[near] == 1) {
								queue[e] = near;
								e++;
							}
						}
					}
					if(count[queue[s]]%k == 0) {
						;
					} else if(count[queue[s]]%k == k-1) {
						count[queue[s]]++;
					} else {
						break;
					}
					/*printf("count\n");
					for(i=0; i<n; i++) {
						printf("%d", count[i]);
					}
					printf("\n");
					printf("left\n");
					for(i=0; i<n; i++) {
						printf("%d", left[i]);
					}
					printf("\n");
					printf("removed\n");
					for(i=0; i<n; i++) {
						printf("%d", removed[i]);
					}
					printf("\n");
					printf("queue\n");
					for(i=0; i<n; i++) {
						printf("%d", queue[i]);
					}
					printf("\n");*/
					s++;
				}
				int check = 1;
				for(i=0; i<n; i++) {
					if(count[i]%k != 0) {
						check = 0;
						break;
					}
				}
				if(check) {
					int gcd = gcd_arr(count, n);
					if(answer[gcd] == 0) {
						sum++;
						answer[gcd_arr(count, n)] = 1;
					}
				}
			}
		}
		answer[n] = 0;
		answer[1] = (mod+pow_mod(2, n-1, mod)-sum)%mod;
		for(i=1; i<=n; i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}