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

#define maxn 1005

using namespace std;

int d[maxn], s[maxn];
int m, k, curmax, dist, fuel;
int res;

int main(){
	cin >> m >> k;
	for(int i = 1; i <= m; ++i)
		cin >> d[i];
	for(int i = 1; i <= m; ++i)
		cin >> s[i];
	res = 0;
	curmax = fuel = s[1];
	dist = d[1];
	int i = 2;
	while(i <= m){
		while(i <= m && curmax >= s[i]){
			dist += d[i];
			fuel += s[i];
			++i;
		}
		res += dist;
// 		cout << "rr " << res << endl;
//  		cout << "i = " << i << endl;
// 		cout << dist << " " << fuel << " " << res << endl;
		int kk = min(dist, fuel);
		fuel -= kk; dist -= kk;
		int num = ((dist + curmax - 1) / curmax);
		res += k * num;
		fuel += num * curmax - dist;
// 		cout << "res = " << res << endl;
		curmax = s[i];
		fuel += s[i];
		dist = d[i];
		++i;
	}
	if(dist != 0){
		res += dist;
//  	cout << "i = " << i << endl;
//  	cout << dist << " " << fuel << " " << res << endl;
		int kk = min(dist, fuel);
		fuel -= kk; dist -= kk;
		res += k * ((dist + curmax - 1) / curmax);
// 		cout << "rr " << res << endl;
	}
	cout << res << endl;
	return 0;
}