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

#define pb push_back
#define mp make_pair

typedef pair <string, string> pss;

struct tp{
	string a, b;
	int t;
};

tp p[1010];

bool operator < (const tp &a, const tp &b){
	return a.t < b.t;
}

int main(){
	//freopen("country.in", "r", stdin);
	//freopen("country.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++){
		cin >> p[i].a >> p[i].b >> p[i].t;
	}
	sort(p, p + n);
	vector <pss> v;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(p[j].t - p[i].t == 0){
				continue;
			}
			if(p[j].t - p[i].t > d){
				break;
			}
			if(p[j].a == p[i].b && p[j].b == p[i].a){
				string a = p[i].a;
				string b = p[i].b;
				if(a > b){
					swap(a, b);
				}
				v.pb(mp(a, b));
			}
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	printf("%d\n", v.size());
	for(int i = 0; i < (int)v.size(); i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}