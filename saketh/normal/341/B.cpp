#include <iostream>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
 
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;

#define akshat poop
int N, arr[100100]; // you want LIS of the permutation

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> N;
	REP(i,N) cin>>arr[i];

	pair<int, int> tosort[100100];
	int akshat = 0;
	int ans = 0;
	vector<int> LIS;
	REP(i, N) {
		if(i == 0) LIS.resize(N);
	}
	LIS.clear();
	LIS.push_back(0);
	LIS.pop_back();

	for (int i = 0; i < N; i++) {
		vector<int>::iterator it=lower_bound(LIS.begin(),LIS.end(), arr[i]);
		if (it == LIS.end()) {
			LIS.push_back(arr[i]);
			tosort[LIS.size()-1].first = ans + 1;
		}
		else {
			LIS[it - LIS.begin()] = arr[i];
			}}cout << LIS.size() << "\n";}