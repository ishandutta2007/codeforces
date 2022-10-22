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

int N, Q;
LL A[1010101];

LL read() {
    LL ret = 0;
    char now = getchar();
    while (now == 10 || now == 32) now = getchar();
    while (now >= 48 && now <= 57) {
        ret = ret * 10 + now - 48;
        now = getchar();
    }
    return ret;
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) A[i]=read();
	LL t=A[1], r=0;
	for (int i=2; i<=N; i++){
		LL k=0, l=0, h=A[i]-t;
		while (l<=h){
			LL m=l+h>>1;
			if ((m+r)/(i-1)+t < A[i]-m || ((m+r)/(i-1)+t == A[i]-m && (m+r)%(i-1) == 0)) k=m, l=m+1;
			else h=m-1;
		}
		if ((r+k)%(i-1) == 0){
			if ((k+r)/(i-1)+t == A[i]-k) r=i-1;
			else r=0;
		}
		else r = (r+k)%(i-1);
		t=A[i]-k;
	}
	for (int i=1; i<=N; i++) printf("%lld ", t-(N-i)+(i<=r));
	printf("\n");
	return 0;
}