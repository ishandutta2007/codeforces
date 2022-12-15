#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e6 + 7;
const long long inf = 1e18; 

int a[MAXN];
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	long long n;
	cin >> n;
 
	long long sum = 0;
	for(long long i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
 
	if(sum == 1){
		cout << "-1\n";
		return 0;
	}
 	
 	long long act_ans = inf;

 	for(long long small = 2; small <= sum; ++small){
 		if(sum % small){
 			continue;
 		}
		long long cnt = 0, before = 0, mid = 0, ans = 0;
		for(long long i = 0; i < n; ++i){
			if(a[i] > 0){
				if(cnt < small / 2){
					before += i;
				}
				else{
					if(cnt == small / 2){
						ans += (small / 2) * i - before;
						before = 0;
						mid = i;
					}
					else{
						ans += i - mid; 
					}
				}
				++cnt;
				if(cnt == small){
					cnt = 0;
				}
			}
		}
	 
		act_ans = min(ans, act_ans);
	}

	cout << act_ans << "\n";
 
	return 0;
}