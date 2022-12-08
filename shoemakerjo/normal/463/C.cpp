#include <bits/stdc++.h>

using namespace std;
#define maxn 2005
#define ll long long
#define pii pair<int, int>
ll nums[maxn][maxn]; //easier if we store as longs
ll sum[maxn][maxn]; //store the sums


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nums[i][j]; //well duh
			sum[i][j] = 0-nums[i][j]; //i will be counted twice
		}
	}

	vector<pii> cur;
	ll csum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0) { //top or left
				cur.clear();
				csum = 0LL;
				int xc = i, yc = j;
				// cout << "starting  " << endl;
				while (xc < n && yc < n) {
					// cout << "    vals:   " << xc << " " << yc << endl;
					cur.push_back(pii(xc, yc));
					csum += nums[xc][yc];
					xc++;
					yc++;
				}
				for (int i = 0; i < cur.size(); i++) {
					sum[cur[i].first][cur[i].second] += csum;
					
				}

			}
			if (i == 0 || j == n-1) { //top or right
				cur.clear();
				csum = 0LL;
				int xc = i, yc = j;
				while (xc < n && yc >= 0) {
					cur.push_back(pii(xc, yc));
					csum += nums[xc][yc];
					xc++;
					yc--;
				}
				for (int i = 0; i < cur.size(); i++) {
					sum[cur[i].first][cur[i].second] += csum;
				
				}
			}
		}
	}

	int xo, yo; //sum for odd values
	ll besto = -1; 
	int xe, ye; //sum for even vals
	ll beste = -1; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i+j)%2 == 0) {
				if (sum[i][j] > beste) {
					beste = sum[i][j];
					xe = i;
					ye = j;
				}
			}
			else {
				if (sum[i][j] > besto) {
					besto = sum[i][j];
					xo = i;
					yo = j;
				}
			}
		}
	}
	// cout << "even  " << beste << "  and odd  " << besto << endl;
	cout << beste + besto << endl;
	cout << xo+1 << " " << yo+1 << " " << xe+1 << " " << ye+1 << endl;
	cin >> n;

}