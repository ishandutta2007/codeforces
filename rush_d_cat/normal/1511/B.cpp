#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
    	int a, b, c;
    	cin >> a >> b >> c;
    	string cc = "1";
    	for (int i = 1; i < c; i ++) cc += "0";

    	c --;
    	a -= c, b -= c;

    	string aa = "1";
    	for (int i = 1; i < a; i ++) aa += "0";
    	for (int i = 1; i <= c; i ++) aa += "0";

    	string bb = "1";
    	for (int i = 1; i < b; i ++) 
    		if (i == b-1) bb += "1"; else bb += "0";
    	for (int i = 1; i <= c; i ++) bb += "0";

    	cout << aa << " " << bb << endl;
    }
}