#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {
	
	int N,x;
	x = 0;
	cin >> N;
	rep(i, 0, N) {
		string tmp;
		cin >> tmp;
		if (tmp[1] == '+') {
			x++;
		}
		else {
			x--;
		}
	}
	cout << x << "\n";

}