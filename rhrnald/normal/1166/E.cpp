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
int x[50];
int y[50][N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", x+i);
		for(int j=0; j<x[i]; j++) scanf("%d", y[i]+j);
		sort(y[i], y[i]+x[i]);
	}
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			int id=0;
			int jd=0;

			bool flag=false;
			while(id<x[i] && jd<x[j]) {
				if(y[i][id]<y[j][jd]) id++;
				if(y[i][id]>y[j][jd]) jd++;
				if(y[i][id]==y[j][jd]) {flag=true; break;}
			}
			if(!flag) {printf("impossible"); return 0;}
		}
	}
	printf("possible");
}