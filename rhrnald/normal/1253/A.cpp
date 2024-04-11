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
int x[N], y[N];
bool b[N];
void proc() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	for(int i=0; i<n; i++) scanf("%d", y+i);
	for(int i=0; i<n; i++) b[i]=(x[i]!=y[i]);

	for(int i=0; i<n; i++) {
		if(b[i]) {
			int d=y[i]-x[i];
			if(d<0) {
				printf("NO\n");
				return;
			}
			for(int j=i; j<n; j++) {
				if(b[j] && x[j]+d!=y[j]) {
					printf("NO\n");
					return;
				}
				if(!b[j]) {
					for(int k=j; k<n; k++) {
						if(b[k]) {
							printf("NO\n");
							return;
						}
					}
					printf("YES\n");
					return;
				}
			}
			printf("YES\n");
			return;
		}
	}
	printf("YES\n");
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--) proc();
}