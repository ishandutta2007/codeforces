#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, B=400;
LL ans;
char str[202020];
int A[202020];
int P[202020];
vector<int> V;

int main(){
	scanf("%s", str+1);
	N = strlen(str+1);
	for (int i=1; i<=N; i++) A[i] = A[i-1] + str[i]-'0';
	for (int k=1; k<=B; k++){
		V.push_back(0);
		for (int i=1; i<=N; i++) V.push_back(k*A[i]-i);
		sort(V.begin(), V.end());
		int a=-123456789, cnt=1;
		for (int x : V){
			if (a == x) cnt++;
			else ans += cnt*((LL)cnt-1)/2, a=x, cnt=1;
		}
		ans += cnt*((LL)cnt-1)/2;
		V.clear();
	}
	for (int i=1; i<=N; i++){
		if (P[A[i]] == 0 && A[i]) P[A[i]] = i;
		for (int j=A[i]-1; (B+1)*(A[i]-j)<=N && j>=0; j--){
			ans += max(0, (i-P[j])/(A[i]-j) - max(B, (i-P[j+1])/(A[i]-j)));
		}
	}
	printf("%lld\n", ans);
	return 0;
}