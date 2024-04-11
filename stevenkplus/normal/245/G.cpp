#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define sz(x) int((x).size())
const int MAXN = 10100;

map<string, int> mymap;

vector<int> conn[MAXN];
int tmp[MAXN];
bool adj[MAXN];

string names[MAXN];
int mapcnt = 0;

int conv(string s) {
	if (mymap[s]) {
		return mymap[s] - 1;
	}
	mymap[s] = mapcnt + 1;
	names[mapcnt] = s;
	return mapcnt++;
}

int N;

int numfriends(int i) {
	for(int j = 0; j < N; ++j) {
		tmp[j] = 0;
		adj[j] = 0;
	}
	int n = sz(conn[i]);
	for(int k = 0; k < n; ++k) {
		int p = conn[i][k];
		for(int j = 0; j < sz(conn[p]); ++j) {
			tmp[conn[p][j]]++;
		}
		adj[p] = true;
	}
	int best = 0;
	int cnt = 0;
	for(int j = 0; j < N; ++j) {
		if (j != i && !adj[j]) {
			if (tmp[j] > best) {
				best = tmp[j];	
				cnt = 0;
			}
			if (tmp[j] == best) {
				cnt++;
			}
		}
	}
	//printf("%s has %d mutual\n", names[i].c_str(), best);
	return cnt;
}
int M;

int main() {
	scanf("%d", &M);
	for(int i = 0; i < M; ++i) {
		string a, b;
		cin >> a >> b;
		int x = conv(a);
		int y = conv(b);
		conn[x].push_back(y);
		conn[y].push_back(x);
	}
	N = mapcnt;
	printf("%d\n", N);
	for(int i = 0; i < N; ++i) {
		int ans = numfriends(i);
		printf("%s %d\n", names[i].c_str(), ans);
	}
	return 0;
}