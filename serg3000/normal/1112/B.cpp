#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GGC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
//#define int long long


signed main(){
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>>b(k, vector<int>(3));
	vector<int>ans(n);
	for(int i = 0; i < k; i++){
		b[i][0] = a[i];
		b[i][1] = 1;
		b[i][2] = i;
	}
	int pr = 0;
	int now = k;
	int colvo = 0;
	for(int q = 0; q < n; q++){
		sort(b.begin(), b.end());
		if(b[0][0] >= 1000){
			break;
		}
		for(int i = 1; i < k; i++){
			b[i][0] -= b[0][0];
			if(b[i][1] <= pr && b[i][1] + b[0][0] - 1 >= pr){
				ans[b[i][2]] = 1;
			}
			b[i][1] += b[0][0];
		}
		if(b[0][1] <= pr && b[0][1] + b[0][0] - 1 >= pr){
			ans[b[0][2]] = 1;
		}
		b[0][0] = 0;
		for(int i = 0; i < k; i++){
			if(b[i][0] == 0){
				colvo++;
				if(now < n){
					b[i][0] = a[now];
					b[i][1] = 1;
					b[i][2] = now;
					now++;
				}
				else{
					b[i][0] = 1e9;
					b[i][1] = 1e9;
					b[i][2] = 1e9;
				}
			}
		}
		double rrr;
		rrr = (double)100 * (double)colvo / (double)n + 0.5;
		if(colvo == n){
			break;
		}
		pr = (int)rrr;
	}
	int cou = 0;
	for(int i = 0; i < n; i++){
		if(ans[i] == 1) cou++;
	}
	cout << cou;
	
	return 0;
}