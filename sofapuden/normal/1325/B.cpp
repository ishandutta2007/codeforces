#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;


int main() {

	int t;
	cin >> t;

	rep(i,0,t){
		int n; 
		cin >> n;
		vector <int> tmpv;
		rep(j, 0, n) {
			int tmpi;
			cin >> tmpi;
			tmpv.push_back(tmpi);

		}
		sort(tmpv.begin(), tmpv.end());
		int u = 0;
		int counter = 0;
		rep(j, 0, tmpv.size()) {
			if (u != tmpv[j]) {
				counter++;
				u = tmpv[j];
			}
		}

		cout << counter << endl;

	}
}