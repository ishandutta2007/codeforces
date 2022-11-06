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
int n,m;
int a[N],b[N],loc[N];
int main(void){
	scanf("%d", &n);

	for(int i=1; i<=n; i++) scanf("%d", a+i);
	for(int i=1; i<=n; i++) scanf("%d", b+i);
	for(int i=1; i<=n; i++) loc[a[i]]=0;
	for(int i=1; i<=n; i++) loc[b[i]]=i;
	
	if(loc[1]) {
		int i=loc[1];
		bool flag=true;
		int cur=1;
		for(int j=i; j<=n; j++) {
			if(b[j]!=cur++) {flag=false; break;}
		}
		if(flag) {
			bool f2=true;
			int c=0;
			while(cur<=n && cur) {
				if(loc[cur++]>c++) {f2=false; break;}
			}
			if(f2) {
				printf("%d", i-1); return 0;
			}
		}
	}
	int ans=1;
	for(int i=1; i<=n; i++) {
		ans=max(loc[i]-i+2, ans);
	}
	printf("%d", ans+n-1);
}