#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 998244353
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, ans=1;
int A[101010];
int B[202020];
int del[1010];

int main(){
	scanf("%d", &N);
	B[0] = MOD;
	for (int i=1; i<=N; i++) scanf("%d", &A[i]);
	for (int i=-200; i<=200; i++){
		for (int j=1; j<=N; j++) B[j] = A[j] - i*j;
		sort(B+1, B+N+1);
		int cnt=1;
		for (int j=1; j<=N; j++){
			if (B[j-1] == B[j]) cnt++, ans=max(ans, cnt);
			else cnt=1;
		}
	}
	for (int i=1; i<=N; i++) B[i] = 0;
	for (int i=1; i<=N; i++){
		int c=1;
		for (int j=i+1; j<=N && j<i+500; j++){
			if (abs(A[j]-A[i])%(j-i) == 0){
				int a = (A[j]-A[i])/(j-i) + 100100;
				B[a]++, del[c++] = a;
				ans = max(ans, B[a]+1);
			}
		}
		while (c--) B[del[c]]=0;
	}

	printf("%d\n", N-ans);
	return 0;
}