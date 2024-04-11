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

int N, M, K;
char in[510][510];
bool vis[510][510];
int ax[]={1,0,0,-1},ay[]={0,1,-1,0};

int main()
{
	scanf("%d%d%d", &N, &M, &K);

	pair<int, int> bp = make_pair(-1, -1);
	for(int i=0;i<N;i++){
		scanf("%s", in[i]);
		for(int j=0;j<M;j++){
			if(in[i][j]=='.') bp = make_pair(i, j);
			vis[i][j] = false;
		}
	}

	queue<pair<int, int> > Q;
	Q.push(bp);

	vector<pair<int, int> > cand;

	while(!Q.empty()){
		pair<int, int> tmp = Q.front();
		Q.pop();

		if(vis[tmp.first][tmp.second]) continue;
		vis[tmp.first][tmp.second] = true;
		cand.push_back(tmp);

		for(int i=0;i<4;i++){
			int x2=tmp.first+ax[i], y2=tmp.second+ay[i];
			if(x2<0 || y2<0 || x2>=N || y2>=M) continue;
			if(in[x2][y2]=='#') continue;

			Q.push(make_pair(x2, y2));
		}
	}

	for(int i=cand.size()-1;i>=cand.size()-K;i--) in[cand[i].first][cand[i].second] = 'X';
	for(int i=0;i<N;i++) puts(in[i]);

	return 0;
}