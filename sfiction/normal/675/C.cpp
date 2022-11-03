#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

map<ll, int> lst;

int main(){
	int n, ans = 1;
	scanf("%d", &n);
	ll sum = 0;
	map<ll, int>::iterator p;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		sum += t;
		if ((p = lst.find(sum)) != lst.end())
			ans = max(ans, ++p->second);
		else
			lst.insert(make_pair(sum, 1));
	}
	printf("%d\n", n - ans);
	return 0;
}