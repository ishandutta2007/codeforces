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

int TC;
int N;
int A[101010];
vector<int> V;

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		scanf("%d", &A[N+1]);
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		long double t=0;
		int l=0, r=N+1;
		long double a=0, b=A[N+1];
		while (l+1<r){
			if ((A[l+1]-a)/(l+1) < (b-A[r-1])/(N+2-r)) t+=(A[l+1]-a)/(l+1), b-=(A[l+1]-a)/(l+1)*(N+2-r), a=A[l+1], l++;
			else t+=(b-A[r-1])/(N+2-r), a+=(b-A[r-1])/(N+2-r)*(l+1), b=A[r-1], r--;
		}
		t += (b-a)/(N+2);
		printf("%.15Lf\n", t);
	}
	return 0;
}