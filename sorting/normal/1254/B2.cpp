#include <bits/stdc++.h>
 
using namespace std;
 
const unsigned long long MAXN = 1e6 + 7;
const unsigned long long inf = 1e18; 

unsigned long long a[MAXN], backup[MAXN];
vector<unsigned long long> d;

unsigned long long diff(long long lvalue, long long rvalue){
	if(lvalue > rvalue){
		return lvalue - rvalue;
	}
	else{
		return rvalue - lvalue;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	unsigned long long n;
	cin >> n;
 
	unsigned long long sum = 0;
	for(unsigned long long i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
		backup[i] = a[i];
	}
 
	if(sum == 1 || sum == 0){
		cout << "-1\n";
		return 0;
	}
 	
 	d.push_back(sum);
 	for(unsigned long long i = 2; i * i <= sum; ++i){
 		if(sum % i == 0){
 			d.push_back(i);
 			if(sum != i * i){
 				d.push_back(sum / i);
 			}
 			sum /= i;
 		}
 	}
 	
 	unsigned long long act_ans = inf;
 	for(unsigned long long small: d){
		unsigned long long j = 0, ans = 0;
		for(int i = 0; i < n; ++i){
			a[i] = backup[i];
		}
		while(j < n){
			if(a[j] >= small){
				a[j] %= small;
				if(a[j] < 0){
					a[j] += small;
				}
			}

			sum = 0ll;
			unsigned long long nxt, l, r;
			for(unsigned long long i = j; i < n; ++i){
				sum += a[i];
				if(small & 1){
					if(sum - a[i] <= small / 2 && sum > small / 2){
						l = i;
					}
				}
				else{
					if(sum - a[i] <= small / 2 && sum > small / 2){
						r = i;
					}
					if(sum - a[i] <= small / 2 - 1 && sum > small / 2 - 1){
						l = i;
					}
				}
				if(sum >= small){
					nxt = i;
					break;
				}
			}
			if(sum == 0){
				break;
			}
			unsigned long long mid;
			if(small & 1){
				mid = l;
			}
			else{
				mid = (l + r) >> 1;
			}
			sum = 0;

			for(unsigned long long i = j; i < n; ++i){
				sum += a[i];
				if(sum >= small){
					ans += diff(i, mid) * (a[i] + small - sum);
					a[i] = sum - small;
					break;
				}
				ans += diff(i, mid) * a[i];
			}
			j = nxt;
		}
	 
		act_ans = min(ans, act_ans);
	}

	cout << act_ans << "\n";
 
	return 0;
}