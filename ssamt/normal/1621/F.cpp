#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int a, b, c;
		scanf("%d %d %d %d", &n, &a, &b, &c);
		char s[n+1];
		scanf("%s", s);
		vector<int> zero, one;
		for(i=0; i<n; i++) {
			if(i == 0 || s[i] != s[i-1]) {
				if(s[i] == '0') {
					zero.push_back(0);
				} else {
					one.push_back(0);
				}
			}
			if(s[i] == '0') {
				zero.back()++;
			} else {
				one.back()++;
			}
		}
		int zeroa = 0, oneb = 0;
		int zerosum = 0, onesum = 0;
		for(i=0; i<zero.size(); i++) {
			zeroa += zero[i]-1;
			zerosum += zero[i];
		}
		for(i=0; i<one.size(); i++) {
			oneb += one[i]-1;
			onesum += one[i];
		}
		long long answer[3];
		if(b <= c) {
			answer[0] = min(zeroa, oneb+1);
			answer[1] = min(zeroa+1, oneb);
			answer[2] = 0;
		} else {
			if(oneb > zeroa) {
				answer[0] = zeroa;
				answer[1] = min(zerosum+1, onesum-1);
				answer[2] = answer[1]-answer[0]-1;
			} else {
				if(s[0] == '0') {
					zero.erase(zero.begin());
				}
				if(!zero.empty() && s[n-1] == '0') {
					zero.pop_back();
				}
				sort(zero.begin(), zero.end());
				answer[0] = answer[1] = oneb;
				answer[2] = 0;
				int sum = 0;
				int count = 0;
				for(i=0; i<zero.size(); i++) {
					sum += zero[i]-1;
					if(sum > oneb) {
						break;
					}
					answer[1]++;
					answer[2]++;
				}
				if(zeroa > oneb) {
					answer[0]++;
				}
			}
		}
		/*for(i=0; i<3; i++) {
			printf("%lld ", answer[i]);
		}
		printf("\n");*/
		printf("%lld\n", a*answer[0]+b*answer[1]-c*answer[2]);
	}
}