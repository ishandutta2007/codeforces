#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5e5 + 1;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

struct node{
	long long c;
	vector<int> key;
	bool operator<(const node &b) const{
		return key < b.key;
	}
}e[N];

int t, n, m, u, v;
long long sum, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = sum = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &e[i].c), e[i].key.clear();
		while(m--){
			scanf("%d%d", &u, &v);
			e[v].key.push_back(u);
		}
		for(int i = 1; i <= n; i++)
			sort(e[i].key.begin(), e[i].key.end());
		sort(e + 1, e + 1 + n);
		for(int i = 1; i <= n; i++){
			if(e[i].key.empty()) continue;
			if(e[i].key == e[i - 1].key) sum += e[i].c;
			else ans = gcd(ans, sum), sum = e[i].c;
		}
		printf("%lld\n", gcd(ans, sum));
	}
	return 0;
}