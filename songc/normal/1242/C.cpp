#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

int N;
int pos[20];
LL ssum[20], num[20];
int D[40000], Su[40000], Sk[40000], chk[101010];
vector<int> S[20];
vector<LL> comp;
LL sum;

int cid(LL x){
	auto it = lower_bound(comp.begin(), comp.end(), x);
	if (it == comp.end() || *it != x) return -1;
	return (int)(it - comp.begin()) + 1;
}

void f(int u, LL r, LL k, int p, int su){
	int t = cid(k);
	if (t == -1) return;
	for (int i=0; i<N; i++){
		if ((chk[t]&(1<<i)) && k == r) {
			D[p] = -1;
			Su[p] = su;
			Sk[p] = r;
		}
		if ((chk[t]&(1<<i)) && ((~p)&(1<<i))) f(i, r, sum-ssum[i]+k, p|(1<<i), su);
	}
}

bool Findpath(int u, LL r, LL k, int p){
	int t = cid(k);
	if (t == -1) return false;
	if (p == 0 && k == sum-ssum[u]+r) return true;
	for (int i=0; i<N; i++){
		if ((chk[t]&(1<<i)) && (p&(1<<i))) {
			if (Findpath(i, r, sum-ssum[i]+k, p^(1<<i))){
				num[i] = k, pos[i] = u;
				return true;
			}
		}
	}
	return false;
}

void makeAns(int p){
	if (D[p] == -1) {
		Findpath(Su[p], Sk[p], sum-ssum[Su[p]]+Sk[p], p);
		return;
	}
	makeAns(D[p]);
	makeAns(p^D[p]);
}

int main(){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		int s, x;
		scanf("%d", &s);
		for (int j=1; j<=s; j++){
			scanf("%d", &x);
			S[i].push_back(x);
			comp.push_back(x);
			sum += x, ssum[i] += x;
		}
	}
	if (sum % N){
		puts("No");
		return 0;
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	sum /= N;
	for (int i=0; i<N; i++) for (int x : S[i]) chk[cid(x)] |= (1<<i);
	for (int i=0; i<N; i++) for (int x : S[i]) f(i, x, sum-ssum[i]+x, 1<<i, i);
	for (int i=1; i<(1<<N); i++){
		if (D[i]) continue;
		for (int p=(i-1)&i; p; p=(p-1)&i){
			if (D[p] && D[i^p]){
				D[i] = p;
				break;
			}
		}
	}
	if (!D[(1<<N)-1]){
		puts("No");
		return 0;
	}
	makeAns((1<<N)-1);
	puts("Yes");
	for (int i=0; i<N; i++) printf("%lld %d\n", num[i], pos[i]+1);
	return 0;
}