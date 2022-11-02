#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define x first
#define y second
#define pb push_back

int power(int a, int b, int c, int ans=1) {
	for (; b; b>>=1, a=(INT)a*a%c) if (b&1) ans=(INT)ans*a%c;
	return ans;
}

const int NN = 1<<21;

char s[NN];
int a[NN], vst[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	for (cin>>T; T--; ) {
		scanf("%s", s);
		int n=strlen(s), cnt=0;
		for (int i=0; i<n; i++) vst[i]=0;
		for (int i=0; i<n; i++) {
			if (strncmp(s+i, "twone", 5)==0) {
				vst[i+2]=1; i+=4;
				continue;
			}
			if (strncmp(s+i, "two", 3)==0 || strncmp(s+i, "one", 3)==0) {
				vst[i+1]=1; i+=2;
			}
		}
		for (int i=0; i<n; i++) if (vst[i]) a[cnt++]=i;
		printf("%d\n", cnt);
		for (int i=0; i<cnt; i++) {
			if (i) putchar(' ');
			printf("%d", a[i]+1);
		}
		puts("");
	}

	return 0;
}