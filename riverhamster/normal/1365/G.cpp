#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1 << 13;
int id[N];
ll OR[13];

void makeSubset(){
	static int popc[N];
	int idc = 0;
	for(int i=0; i<N; i++){
		popc[i] = popc[i >> 1] + (i & 1);
		if(popc[i] == 6) id[++idc] = i;
	}
}

int main(){
	makeSubset();
	int n;
	scanf("%d", &n);
	for(int i=0; i<13; i++){
		static int val[N];
		int vc = 0;
		for(int j=1; j<=n; j++)
			if((id[j] >> i) & 1)
				val[++vc] = j;
		if(vc == 0) continue;
		printf("? %d ", vc);
		for(int j=1; j<=vc; j++) printf("%d ", val[j]);
		putchar('\n'); fflush(stdout);
		scanf("%lld", OR + i);
	}
	printf("! ");
	for(int i=1; i<=n; i++){
		ll s = 0;
		for(int j=0; j<13; j++)
			if(((id[i] >> j) & 1) == 0) s |= OR[j];
		printf("%lld ", s);
	}
	return 0;
}