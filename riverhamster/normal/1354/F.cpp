#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

struct item{
	int a, b, id;
};
item a[80];
int f[80][80];
bool from[80][80];
bool isA[80];
int A[80];

int main(){
	// File("cf1354f");
	int T;
	scanf("%d", &T);
	while(T--){
		int k, n;
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; i++)
			scanf("%d%d", &a[i].a, &a[i].b), a[i].id = i;
		sort(a + 1, a + 1 + n, [](item p, item q) {return p.b < q.b;});
		memset(f, 0x9f, sizeof(f));
		f[0][0] = 0;
		for(int i=1; i<=n; i++){
			f[i][0] = f[i-1][0] + a[i].b * (k - 1);
			for(int j=max(1, k - (n - i)), li=min(i, k); j<=li; j++){
				int tA = a[i].a + a[i].b * (j - 1) + f[i-1][j-1];
				int tB = a[i].b * (k - 1) + f[i-1][j];
				if(tA > tB)
					f[i][j] = tA, from[i][j] = true;
				else
					f[i][j] = tB, from[i][j] = false;
			}
		}
		for(int p=n, q=k; p!=0; --p){
			isA[p] = from[p][q];
			if(isA[p]) A[q] = a[p].id;
			q -= from[p][q];
		}
		printf("%d\n", n * 2 - k);
		for(int i=1; i<k; i++) printf("%d ", A[i]);
		for(int i=1; i<=n; i++)
			if(!isA[i]) printf("%d -%d ", a[i].id, a[i].id);
		printf("%d\n", A[k]);
	}
	return 0;
}