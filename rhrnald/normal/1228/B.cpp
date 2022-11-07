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

const int N = 1001;
int n,m;
int x;

int b[N][N];

const int MOD=1000000007;
ll pow(int c) {
	if(c==0) return 1;
	if(c==1) return 2;
	if(c==2) return 4;
	ll t=pow(c/2);
	if(c&1) return (t*t%MOD)*2%MOD;
	return t*t%MOD;
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		for(int j=0; j<x; j++) b[i][j]=1;
		b[i][x]=2;
	}
	for(int i=0; i<m; i++) {
		scanf("%d", &x);
		for(int j=0; j<x; j++) {
			if(b[j][i]==2) {printf("0"); return 0;}
			b[j][i]=1;
		}
		if(b[x][i]==1) {printf("0"); return 0;}
		b[x][i]=2;
	}
	int cnt=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) if(!b[i][j]) cnt++;
	printf("%lld", pow(cnt));
}