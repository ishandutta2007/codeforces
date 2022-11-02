#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

pii p[1010];
ll need[1010];

int main(){
	//freopen("parking.in", "r", stdin);
	//freopen("parking.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p[i].second, &p[i].first);
	}
	sort(p, p + n);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		cin >> need[i];
	}
	int j = 0;
	ll sum = 0, ans = 0;
	for(int i = 0; i < n; i++){
		while(p[i].second > 0){
			if(j < t && sum + p[i].second >= need[j]){
				ans += (ll)p[i].first * (j + 1) * (need[j] - sum);
				p[i].second -= need[j] - sum;
				sum = need[j];
				j++;
				continue;
			}
			ans += (ll)p[i].first * (j + 1) * p[i].second;
			sum += p[i].second;
			p[i].second = 0;
		}
	}
	cout << ans << endl;
	return 0;
}