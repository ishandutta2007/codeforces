#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;

int N, M;
LL D[101010];
vector<pii> A, B;
vector<LL> ansu, ansv, answ;

int main(){
	scanf("%d %d", &N, &M);
	for (int i=1; i<=M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		D[u] += w;
		D[v] -= w;
	}
	for (int i=1; i<=N; i++){
		if (D[i] > 0) A.push_back(pii(D[i], i));
		if (D[i] < 0) B.push_back(pii(-D[i], i));
	} 
	while (!A.empty()){
		if (A.back().first == B.back().first){
			ansu.push_back(A.back().second);
			ansv.push_back(B.back().second);
			answ.push_back(A.back().first);
			A.pop_back();
			B.pop_back();
		}
		else if (A.back().first > B.back().first){
			ansu.push_back(A.back().second);
			ansv.push_back(B.back().second);
			answ.push_back(B.back().first);
			A[A.size()-1].first -= B.back().first;
			B.pop_back();
		}
		else{
			ansu.push_back(A.back().second);
			ansv.push_back(B.back().second);
			answ.push_back(A.back().first);
			B[B.size()-1].first -= A.back().first;
			A.pop_back();
		}
	}
	printf("%d\n", ansu.size());
	for (int i=0; i<ansu.size(); i++) printf("%lld %lld %lld\n", ansu[i], ansv[i], answ[i]);
	return 0;
}