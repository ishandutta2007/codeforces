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

typedef unsigned long long ull;

const string ans[4] = {"byte", "short", "int", "long"};
const ull maxn[4] = {127, 32767, 2147483647LL, 9223372036854775807LL};

int main(){
	//freopen("tests.in", "r", stdin);
	//freopen("tests.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	if(s.length() > 19){
		printf("BigInteger\n");
		return 0;
	}
	ull n = 0;
	for(int i = 0; i < (int)s.length(); i++){
		n = n * 10 + s[i] - '0';
	}
	for(int i = 0; i < 4; i++){
		if(n <= maxn[i]){
			cout << ans[i] << endl;
			return 0;
		}
	}
	printf("BigInteger\n");
	return 0;
}