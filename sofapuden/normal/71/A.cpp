#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {
	
	int N;
	cin >> N;

	rep(i, 0, N) {
		string tmp;
		cin >> tmp;
		if (tmp.size() > 10) {
			cout << tmp[0] << tmp.size() - 2 << tmp[tmp.size() - 1] << "\n";
		}
		else
		{
			cout << tmp << "\n";
		}
	}

	return 0;
}