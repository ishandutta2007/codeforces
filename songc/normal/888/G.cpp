#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL ans;
int A[202020];
int L[6060606], R[6060606], num=2;

void pushTr(int id, int k, int x){
	if (k<0) return;
	if (x&(1<<k)){
		if (!R[id]) R[id] = num++;
		pushTr(R[id], k-1, x);
	}
	else{
		if (!L[id]) L[id] = num++;
		pushTr(L[id], k-1, x);
	}
}

int minXor(int id, int k, int x){
	if (k<0) return 0;
	if (x&(1<<k)){
		if (!R[id]) return minXor(L[id], k-1, x) + (1<<k);
		return minXor(R[id], k-1, x);
	} 
	else{
		if (!L[id]) return minXor(R[id], k-1, x) + (1<<k);
		return minXor(L[id], k-1, x);
	}
}

void DNC(int k, int s, int e){
	if (k<0 || s>=e) return;
	int t, Min=(1<<30);
	for (t=s; (~A[t]&(1<<k)) && t<=e; t++);
	DNC(k-1, s, t-1);
	DNC(k-1, t, e);
	if (t>e || t<=s) return;
	for (int i=s; i<t; i++) pushTr(1, 29, A[i]);
	for (int i=t; i<=e; i++) Min = min(Min, minXor(1, 29, A[i]));
	for (int i=1; i<num; i++) L[i] = R[i] = 0;
	num = 2, ans += Min;
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%d", &A[i]);
	sort(A+1, A+N+1);
	DNC(29, 1, N);
	printf("%lld\n", ans);
	return 0;
}