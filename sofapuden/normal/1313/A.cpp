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

	rep(i, 0, t) {
	

		vector <int> restaurant;

		rep(j, 0, 3) {
			int tmp;
			cin >> tmp;
			restaurant.push_back(tmp);
		}

		sort(restaurant.begin(), restaurant.end());
		int sum = 0;
		rep(j, 0, 3) {
			if (restaurant[j] == 1) {
				sum += 1;
			}
			else if (restaurant[j] == 2) {

				if (j != 2) {
					sum += 2;
					restaurant[2] -= 1;
				}
				else {
					sum += 1;
				}
			}
			else if (restaurant[j] == 3) {
				if (j == 0) {
					sum += 3;
					restaurant[1] -= 1;
					restaurant[2] -= 1;
				}
				else if (j == 1) {
					sum += 2;
					restaurant[2] -= 1;
				}
				else {
					sum += 1;
				}

			}
			else if (restaurant[j] >= 4) {
				if (j == 0) {
					sum += 4;
				}
				else if (j == 1) {
					sum += 2;
				}
				else {
					sum += 1;

				}
			}
		}

		cout << sum << endl;

	}

	return 0;
}