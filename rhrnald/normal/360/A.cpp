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

const int N = 5011;
int n,m;

int cur[N];
int M[N];
int c[N], l[N],r[N], val[N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) M[i]=1e9;
	for(int i=0; i<m; i++) {
		scanf("%d%d%d%d", c+i, l+i, r+i, val+i);
		if(c[i]==1) {
			for(int j=l[i]; j<=r[i]; j++) cur[j]+=val[i];
		} else {
			for(int j=l[i]; j<=r[i]; j++) {
				M[j]=min(M[j], val[i]-cur[j]);
			}
		}
	}
	for(int i=1; i<=n; i++) cur[i]=0;
	for(int i=0; i<m; i++) {
		if(c[i]==1) {
			for(int j=l[i]; j<=r[i]; j++) cur[j]+=val[i];
		}
		if(c[i]==2) {
			bool flag=true;
			for(int j=l[i]; j<=r[i]; j++) {
				if(M[j]+cur[j]==val[i]) {flag=false;break;}
			}
			if(flag) {
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=1; i<=n; i++) printf("%d ", M[i]);
}