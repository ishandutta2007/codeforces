#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define inf 0x3f3f3f3f3f3f3f3fLL

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

typedef long long INT;

typedef pair<INT, int> pii;

template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}

priority_queue<pii, vector<pii>, greater<pii> > pq;
#define NN 222222

INT a[NN];
int sgn[NN];

int main() {
	
	int N, K, cnt, i, id, u;
	INT x, mn, r;
	
	scanf("%d%d%I64d", &N, &K, &x);
	
	for (i=0; i<N; i++) scanf("%I64d", a+i);
	
	cnt=0;
	for (i=0; i<N; i++) {
		if (a[i]<0) cnt++;
	}
	
	if (cnt%2==0) {
		mn=inf;
		for (i=0; i<N; i++) {
			if (abs(a[i])<mn) {
				mn=abs(a[i]); id=i;
			}
		}
		
		if (abs(a[id])<x*K) {
			r=(abs(a[id])+x)/x;
			
			if (a[id]<0) a[id]+=r*x;
			else a[id]-=r*x;
			
			K-=r;
			for (i=0; i<N; i++) {
				if (a[i]>=0) sgn[i]=1;
				else sgn[i]=-1;
				a[i]=abs(a[i]);
			}
			
			for (i=0; i<N; i++) pq.push(pii(a[i], i));
			for (i=0; i<K; i++) {
				u=pq.top().y; pq.pop();
				a[u]+=x;
				pq.push(pii(a[u], u));
			}
			
			for (i=0; i<N; i++) a[i]*=sgn[i];
		} else {
			if (a[id]<0) a[id]+=x*K;
			else a[id]-=x*K;
		}
	} else {
		for (i=0; i<N; i++) {
			if (a[i]>=0) sgn[i]=1;
			else sgn[i]=-1;
			a[i]=abs(a[i]);
		}
		
		for (i=0; i<N; i++) pq.push(pii(a[i], i));
		for (i=0; i<K; i++) {
			u=pq.top().y; pq.pop();
			a[u]+=x;
			pq.push(pii(a[u], u));
		}
		
		for (i=0; i<N; i++) a[i]*=sgn[i];
	}
	
	for (i=0; i<N; i++) printf("%I64d ", a[i]);
	puts("");
	
	return 0;
}