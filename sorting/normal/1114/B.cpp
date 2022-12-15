#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

long long a[N], b[N];
vector<long long> res;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, k;

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b+n, greater<long long>());

	long long x = b[m*k - 1], cnt = 0, score = 0;
	long long cnt_x = 0;

	for(int i = m*k - 1; i >= 0; i--, cnt_x++){
		if(b[i] != x){
			break;
		}
	}

	//cout << x << "\n";

	for(int i = 0, j = 0; i < n, j < k; i++){
		if(a[i] >= x){
			if(a[i] == x){
				if(!cnt_x){
					continue;
				}
				cnt_x--;
			}

			cnt++;
			score += a[i];

			//cout << a[i] << "a\n"; 

			if(cnt == m){
				res.push_back(i+1);
				cnt = 0;
				j++;
			}
		}
	}
	res.pop_back();

	cout << score << "\n";

	for(long long p: res){
		cout << p << " ";
	}
	cout << "\n";

	return 0;
}