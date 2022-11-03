#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int win[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int n;
map<string, int> score;
map<string, vector<int> > cnt;
char buff[256];

vector<pair<vector<int>, string> > first, second;

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	gets(buff);
	sscanf(buff, "%d", &n);
	for (int i = 0; i<n; i++) {
		int k;
		gets(buff);
		sscanf(buff, "%d", &k);
		for (int j = 0; j<k; j++) {
			gets(buff);
			string s = buff;
			if (score.find(s) == score.end()) {
				score[s] = 0;
				cnt[s] = vector<int>(64, 0);
			}
			if (j < 10) score[s] += win[j];
			cnt[s][j]++;
		}
	}
	for (map<string, int>::iterator it = score.begin(); it != score.end(); it++) {
		string s = it->first;
//		printf("%s %d  %d %d %d\n", s.c_str(), score[s], cnt[s][0], cnt[s][1], cnt[s][2]);
		vector<int> t1, t2;

		t1.push_back(score[s]);
		for (int j = 0; j<64; j++) t1.push_back(cnt[s][j]);

		t2.push_back(cnt[s][0]);
		t2.push_back(score[s]);
		for (int j = 1; j<64; j++) t2.push_back(cnt[s][j]);

		first.push_back(make_pair(t1, s));
		second.push_back(make_pair(t2, s));
	}
	sort(first.begin(), first.end());
	reverse(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	printf("%s\n", first[0].second.c_str());
	printf("%s\n", second[0].second.c_str());

	return 0;
}