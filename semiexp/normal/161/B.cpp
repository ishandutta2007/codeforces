#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long i64;

int N, K;
vector<pair<int, int> > sto, pen;
i64 dp[1001][1001]; int from[1001][1001];
vector<int> ret[1000];

int main()
{
	int x, y;
	scanf("%d%d", &N, &K);

	double sol = 0;

	for(int i=0;i<N;i++){
		scanf("%d%d", &x, &y);
		if(y==1) sto.push_back(make_pair(x, i+1));
		if(y==2) pen.push_back(make_pair(x, i+1));
	}
	sort(sto.begin(), sto.end());
	sort(pen.begin(), pen.end());

	if(sto.size() < K){
		for(int i=0;i<sto.size();i++){
			sol += sto[i].first / 2.0;
			ret[i].push_back(sto[i].second);
		}
		int at = sto.size();
		for(int i=0;i<pen.size();i++){
			sol += pen[i].first;
			ret[at++].push_back(pen[i].second);
			if(at>=K) at = K-1;
		}
	}else{
		int at = 0;
		for(int i=sto.size()-1;i>=sto.size()-(K-1);i--){
			sol += sto[i].first / 2.0;
			ret[at++].push_back(sto[i].second);
		}
		sol -= min(sto[0].first, pen.size()>0 ? pen[0].first : 1000000000) / 2.0;
		for(int i=sto.size()-(K-1)-1;i>=0;i--){
			sol += sto[i].first;
			ret[at].push_back(sto[i].second);
		}
		for(int i=0;i<pen.size();i++){
			sol += pen[i].first;
			ret[at].push_back(pen[i].second);
		}
	}

	printf("%.1f\n", sol);
	for(int i=0;i<K;i++){
		printf("%d", ret[i].size());
		for(int j=0;j<ret[i].size();j++) printf(" %d", ret[i][j]);
		puts("");
	}

	return 0;
}