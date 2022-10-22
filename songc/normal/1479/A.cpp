#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 1'000'000'007 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
int A[101010];

int query(int x){
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main(){
	scanf("%d", &N);
	int l=1, r=N;
	while (l+3<r){
		int m1 = l + (r-l)/3;
		int m2 = l + (r-l)/3*2;
		int r1 = query(m1);
		int r2 = query(m2);
		if (r1 > r2) l = m1;
		else r = m2;
	}
	for (int i=l; i<=r; i++) A[i] = query(i);
	for (int i=l+1; i<r; i++) if (A[i] < A[i-1] && A[i] < A[i+1]){
		printf("! %d\n", i);
		return 0;
	}
	if (A[l] < A[l+1]) printf("! %d\n", l);
	else printf("! %d\n", r);
	return 0;
}