#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;

int N;
LL ans;
pii A[3030], P[3030];

LL CCW(pii a, pii b){return a.first*b.second-a.second*b.first;}
LL CCW(pii a, pii b, pii c){return CCW(pii(b.first-a.first, b.second-a.second), pii(c.first-a.first, c.second-a.second));}
int nid(int k){return (k==N-1)?1:k+1;}

int main(){
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%lld %lld", &A[i].first, &A[i].second);
	for (int i=0; i<N; i++){
		P[0] = A[i];
		for (int j=0; j<i; j++) P[j+1] = A[j];
		for (int j=i+1; j<N; j++) P[j] = A[j];
		sort(P+1, P+N, [&](pii a, pii b){
			if (a.first-P[0].first>=0 && b.first-P[0].first<0) return true;
			if (a.first-P[0].first<0 && b.first-P[0].first>=0) return false;
			return CCW(P[0], a, b) > 0;
		});

		int t=1;
		for (int j=1; j<N; j++){
			while (nid(t) != j && CCW(P[0], P[j], P[nid(t)])>0) t=nid(t);
			int k;
			if (t >= j) k = t-j;
			else k = t+N-1-j;
			ans -= k*(k-1)/2;
			if (t == j) t++;
		}
		ans += ((LL)N-1)*(N-2)*(N-3)/6;
	}
	printf("%lld\n", ans*(N-4)/2);
	return 0;
}