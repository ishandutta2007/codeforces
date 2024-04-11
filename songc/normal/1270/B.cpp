#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
int A[202020];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		for (int i=1; i<=N; i++) scanf("%d", &A[i]);
		int Min=1234567890, mini;
		bool tf = true;
		for (int i=1; i<=N; i++){
			if (Min+1 <= A[i]-i){
				printf("YES\n%d %d\n", mini, i);
				tf = false;
				break;
			}
			if (Min > A[i]-i) Min = A[i]-i, mini=i;
		}
		if (tf){
			Min=1234567890;
			for (int i=1; i<=N/2; i++) swap(A[i], A[N-i+1]);
			for (int i=1; i<=N; i++){
				if (Min+1 <= A[i]-i){
					printf("YES\n%d %d\n", N-i+1, N-mini+1);
					tf = false;
					break;
				}
				if (Min > A[i]-i) Min = A[i]-i, mini=i;
			}
		}
		if (tf) puts("NO");
	}
	return 0;
}