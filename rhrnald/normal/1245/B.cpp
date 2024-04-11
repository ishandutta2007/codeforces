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
int r, p, s;
string x;
char C[N];
void proc() {
	scanf("%d", &n);
	scanf("%d%d%d", &r, &p, &s);
	cin >> x;

	int ans=0;
	for(int i=0; i<n; i++) {
		if(x[i]=='R') {
			if(p) {
				C[i]='P';
				p--;
				ans++;
			} else {
				C[i]='x';
			}
		}
		if(x[i]=='P') {
			if(s) {
				C[i]='S';
				s--;
				ans++;
			} else {
				C[i]='x';
			}
		}
		if(x[i]=='S') {
			if(r) {
				C[i]='R';
				r--;
				ans++;
			} else {
				C[i]='x';
			}
		}
	}
	if(ans<(n+1)/2) {
		printf("NO\n");
		return;
	}
	for(int i=0; i<n; i++) {
		if(C[i]!='x') continue;
		if(r) {
			C[i]='R';
			r--;
			continue;
		}
		if(s) {
			C[i]='S';
			s--;
			continue;
		}
		if(p) {
			C[i]='P';
			p--;
			continue;
		}
	}
	printf("Yes\n");
	for(int i=0; i<n; i++) printf("%c", C[i]); printf("\n");
}
int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--) proc();
}