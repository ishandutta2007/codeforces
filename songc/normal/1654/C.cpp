#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
multiset<LL> A; 

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		int x=0;
		LL S=0;
		A.clear();
		for (int i=N; i>0; i--){
			scanf("%d", &x);
			A.insert(x);
			S += x;
		}
		vector<LL> V;
		V.pb(S);
		while (A.size()){
			LL a = V.back();
			V.pop_back();
			if (A.find(a) != A.end()){
				A.erase(A.find(a));
				continue;
			}
			if (a <= 1) break;
			V.pb(a/2), V.pb((a+1)/2);
		}
		puts(A.empty()?"YES":"NO");
	}
	return 0;
}