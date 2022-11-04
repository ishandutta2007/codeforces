#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

vector<pair<int, int> > V;

int n;

set<int> S;

int main(){
	scanf("%d", &n);
	int pre = 1;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(!S.insert(x).second) V.push_back(make_pair(pre, i)), pre = i + 1,S.clear();
	}
	if(!V.size()) printf("-1\n");
	else{
		V.back().second = n;
		printf("%d\n", int(V.size()));
		for(int i = 0; i < int(V.size()); ++i){
			printf("%d %d\n", V[i].first, V[i].second);
		}
	}
	return 0;
}