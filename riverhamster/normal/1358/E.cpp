#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 500005;
ll s[N];
ll premin[N];

int main(){
//	freopen("cf1358e.in", "r", stdin);
//	freopen("cf1358e.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int li = (n + 1) / 2;
	for(int i=1; i<=li; i++)
		scanf("%lld", s + i);
	scanf("%lld", s + li + 1);
	ll ex = s[li + 1];
	fill(s + li + 1, s + n + 1, ex);
	for(int i=n-1; i>=1; i--)
		s[i] += s[i + 1];
	if(ex > 0){
		if(s[1] <= 0) puts("-1");
		else printf("%d\n", n);
		return 0;
	}
	for(int i=1; i<=li; i++)
		s[i] -= ex * (li - i);
	premin[1] = s[1];
	for(int i=2; i<=n; i++)
		premin[i] = min(premin[i - 1], s[i]);
	for(int i=li; i>=1; i--){
		if(premin[i] > -ex * (li - i)){
			printf("%d\n", n - i + 1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}