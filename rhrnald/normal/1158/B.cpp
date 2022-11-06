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
int ans[N];
int main(void){
	scanf("%d%d", &n, &m);
	if(m==1) {
		printf("0");
		for(int i=1; i<n; i++) printf("1");
		return 0;
	}
	int T=(n-m)/2+1;
	for(int i=0; i<T-1; i++) x[i]=1; x[T]=0;
	for(int i=0; i<n; i++) printf("%d", x[i%T]);
}