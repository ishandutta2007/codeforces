#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

long long num[5];
long long cost[5];
int n;
long long p[100];
long long cur_cost;

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	for(int i = 0; i < 5; ++i)
		cin >> cost[i];
	cur_cost = 0;
	for(int i = 0; i < n; ++i){
		cur_cost += p[i];
		for(int i = 5; i > 0; --i){
			if(cur_cost >= cost[i - 1])
				num[i - 1] += cur_cost / cost[i - 1];
			cur_cost %= cost[i - 1];
		}
	}
	for(int i = 0; i < 5; ++i)
		cout << num[i] << ' ';
	cout << '\n' << cur_cost << '\n';

	return 0;
}