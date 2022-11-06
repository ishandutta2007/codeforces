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

const int N = 1000011;
int n,m;
const int MOD=1000000007;
int f[N];
int main(void){
	scanf("%d%d", &n, &m);
	int M=max(n,m);
	f[0]=2;
	f[1]=2;
	for(int i=2; i<=M; i++) f[i]=(f[i-1]+f[i-2])%MOD;
	int ans=f[n]+f[m]-2;
	printf("%d", (ans%MOD+MOD)%MOD);
}