#include<iostream>

using namespace std;

int main() {
//ios_base::sync_with_stdio(false);
	int n;
	//cin >> n;
scanf("%d", &n);
	long long sx = 0, sy = 0, s2 = 0;
	for(int i = n; i > 0; i--) {
		int x, y;
		//cin >> x >> y;
scanf("%d %d", &x,&y);
		sx += x; s2 += x * x;
		sy += y; s2 += y * y;
	}
	cout << n * s2 - sx * sx - sy * sy << endl;
}