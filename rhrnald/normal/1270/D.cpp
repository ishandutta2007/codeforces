#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,k,x,y;
int p,q;
bool ch[N];
int main(void){
	scanf("%d%d", &n, &k);
	printf("? "); for(int i=1; i<=k; i++) printf("%d ", i); printf("\n"); fflush(stdout);
	scanf("%d %d", &x, &y);
	for(int i=1; i<=k; i++) {
		printf("? ");
		for(int j=1; j<=k+1; j++) {
			if(i==j) continue;
			printf("%d ", j);
		}
		printf("\n"); fflush(stdout);
	
		int a,b;
		scanf("%d%d", &a, &b);

		if(i!=x) ch[i]=(a==x);
		else {
			p=a;
			q=b;
		}
	}
	ch[k+1]=true;
	int cnt=0;
	int ans;
	for(int i=1; i<=k; i++) if(ch[i]) cnt++;
	if(ch[p]) {
		if(q>y) {
			ans=k-cnt;
		} else {
			ans=cnt+1;
		}
	} else {
		if(q>y) {
			ans=cnt+1;
		} else {
			ans=k-cnt;
		}
	}
	printf("! %d\n", ans);
}