#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, P;
int A[1010101], B[1010101];

int main(){
	int a, b;
	scanf("%d %d %d", &N, &M, &P);
	for (int i=1; i<=N; i++) scanf("%d", &A[i]);
	for (int i=1; i<=N; i++) if (A[i]%P!=0){a=i-1; break;}
	for (int i=1; i<=M; i++) scanf("%d", &B[i]);
	for (int i=1; i<=M; i++) if (B[i]%P!=0){b=i-1; break;}
	printf("%d\n", a+b);
	return 0;
}