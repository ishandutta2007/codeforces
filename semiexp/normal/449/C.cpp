#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define MOD 1000000009
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)

int N;
int minp[100100];

int cnt[100100];
int rob[100100];
vector<int> cands[100100];

int main()
{
	scanf("%d", &N);

	for(int i=0;i<=N;i++) {
		minp[i] = -1;
		cnt[i] = 0;
		rob[i] = -1;
	}

	for(int i=2;i<=N;i++) if(minp[i] == -1) {
		minp[i] = i;
		for(int j=i;j<=N;j+=i) if(minp[j] == -1) minp[j] = i;
	}

	for(int i=2;i<=N;i++) {
		cnt[minp[i]]++;
	}
	for(int i=3;i<=N/2;i++) if(i == minp[i]) { //is prime
		if(cnt[i] % 2 == 1) {
			rob[2*i] = i;
			cnt[2]--;
		}
	}
	//puts("aaa");
	for(int i=2;i<=N;i++) {
		if(rob[i] == -1) cands[minp[i]].push_back(i);
		else cands[rob[i]].push_back(i);
	}
	vector<pair<int, int> > ret;
	for(int i=2;i<=N;i++) {
		for(int j=0;j<(int)cands[i].size()-1;j+=2) ret.push_back(make_pair(cands[i][j], cands[i][j+1]));
	}
	
	printf("%d\n", ret.size());
	for(int i=0;i<ret.size();i++) printf("%d %d\n", ret[i].first, ret[i].second);

	return 0;
}