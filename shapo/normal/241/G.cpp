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

#define maxn 503

int n;
int s[maxn];
double radius[maxn];
double p[maxn];
double x[maxn];

int relax(int i, int j){
	int t = s[j];
	radius[i] = min(radius[i], (x[i] - x[t]) * (x[i] - x[t]) / 4 / radius[t]);
	return 0;
}

int main(){
	int ns = 0, nk = 0;
	double sum = 0;
//  	cin >> n;
 	n = 400;
	int dt = 0;
	cout << 400 << endl;
	for(int i = 1; i <= n; ++i){
// 		cin >> x[i] >> p[i];
		if(i == 1 || i == n)
			p[i] = 1000000.0;
		else
			p[i] = n - i;
		if(i < n)
			x[i] = dt;
		else x[i] = 1000000.0;
		cout << int(x[i]) << " " << int(p[i]) << endl;
		//cout << "dt = " << dt << endl;
		//cout << "ns = " << ns << endl;
		//cout << "p = " << p[i] << endl;
 		double dx = sqrt(4 * p[i] * p[i - 1]);
 		dt += int(dx + 1.0);
// 		radius[i] = p[i];
// 		for(int j = 0; j < min(ns, 300); ++j)
// 			relax(i, ns - j - 1);
// 		while(ns && radius[s[ns - 1]] <= radius[i]){
// 			cout << " id = " << s[ns - 1] << " rad = " << radius[s[ns - 1]] << endl;
// 			--ns;
// 		}
// 		s[ns++] = i;
// 		sum += radius[i];
// 		cout << "radius = " << radius[i] << endl;
	}
	//cout << sum << endl;
	return 0;
}