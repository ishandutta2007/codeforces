#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long i64;

struct range
{
	int left, right;
	range(){ left = right = 0; }
	range(int i, int j){ left = i; right = j; }
};

int _L1, _R1, _L2, _R2;
i64 L1, R1, L2, R2;

pair<range, range> solve(i64 L, i64 R, int D)
{
	i64 mn = 1 + ((L + (1LL << (i64)(D-1)) - 1) >> D);
	i64 mx = (R + (1LL << (i64)(D-1))) >> D;
	if(mx-mn<0) return make_pair(range(-1, -1), range(-1, -1));
	if(mx-mn>=2){
		return make_pair(range((1<<(D-1))-1, (1<<(D-1))-1), range((1<<(D-1))-1, (1<<(D-1))-1));
	}
	if(mx-mn==1){
		mn = (mn << D) - (1 << (D-1));
		mx = (mx << D) - (1 << (D-1));
		return make_pair(range(min((1LL<<(D-1))-1, mn-L), (1<<(D-1))-1), range((1<<(D-1))-1, min((1LL<<(D-1))-1, R-mx)));
	}
		mn = (mn << D) - (1 << (D-1));
		mx = (mx << D) - (1 << (D-1));
		return make_pair(range(min((1LL<<(D-1))-1, mn-L), min((1LL<<(D-1))-1, R-mx)), range(-1, -1));
}

i64 count(range& A, range& B)
{
	return min(A.left, B.left) + min(A.right, B.right) + 1;
}

int main()
{
	scanf("%d%d%d%d", &_L1, &_R1, &_L2, &_R2);
	L1 = _L1; R1 = _R1; L2 = _L2; R2 = _R2;

	i64 ret = 0;
	for(int i=30;i>=1;i--){
		pair<range, range> sol1=solve(L1, R1, i), sol2=solve(L2, R2, i);
		ret = max(ret, count(sol1.first, sol2.first));
		ret = max(ret, count(sol1.second, sol2.first));
		ret = max(ret, count(sol1.first, sol2.second));
		ret = max(ret, count(sol1.second, sol2.second));
	}

	printf("%d\n", (int)ret);
	return 0;
}