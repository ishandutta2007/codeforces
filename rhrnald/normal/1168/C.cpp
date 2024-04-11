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
int x[N];
bool y[N][20];

int c[N][20];

vector<int> v[20],cur;
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", x+i);
		for(int j=0; j<20; j++) {
			y[i][j]=x[i]&1; x[i]>>=1;
			if(y[i][j]) v[j].push_back(i);
		}
	}

	for(int i=n-1; i>=0; i--) {
		for(int j=0; j<20; j++) {
			if(y[i][j]) {
				c[i][j]=i;
				if(v[j].back()==i) continue;
				cur.push_back(*upper_bound(all(v[j]), i));
			} else c[i][j]=INF;
		}
		
		for(int e : cur) {
			for(int j=0; j<20; j++) c[i][j]=min(c[i][j], c[e][j]);
		}

		cur.clear();
	}

	for(int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d", &a, &b); a--; b--;
		bool flag=false;
		for(int j=0; j<20; j++) {
			if(y[b][j]) {
				if(c[a][j]<=b) {flag=true; break;}
			}
		}
		if(flag) printf("Shi\n");
		else printf("Fou\n");
	}
}