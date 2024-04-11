#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int gcd(int a, int b) {
    if (a == 0 || b == 0) return a + b;
    return a > b ? gcd(a % b, b) : gcd(b % a, a);
}

int p[] = {1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401,1};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	map < int, int > cache;
	for (int i = 2; i <= 25; ++i) {
	    int n = (1 << i) - 1;
	    /*int res = 0;
	    for (int j = 1; j < n; ++j) {
	        res = max(res, gcd(n ^ j, n & j));
	    }
	    cout << res << ",";*/
	    cache[n] = p[i - 2];
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	    int a;
	    cin >> a;
	    //a = i + 1;
	    if (cache.count(a)) {
	        cout << cache[a] << endl;
	        continue;
	    }
	    int res = 1;
	    while (res <= a) {
	        res *= 2;
	    }
	    cout << res - 1 << endl;
	}

	return 0;
}