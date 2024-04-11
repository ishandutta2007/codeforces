#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)

using namespace std;

int main() {
	
	int N, K;
	cin >> N >> K;

	vector <int> scores;

	rep(i, 0, N) {
		int tmp;
		cin >> tmp;
		scores.push_back(tmp);

	}

	int comparenumber, thesum;
	comparenumber = scores[K-1];
	thesum = 0;

	rep(i, 0, scores.size()) {
		if (scores[i] >= comparenumber && scores[i] != 0) {
			thesum += 1;
		}
	}

	cout << thesum;

	return 0;
}