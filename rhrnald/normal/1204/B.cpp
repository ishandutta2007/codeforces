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
int n,l,r;
int ans[N];
int main(void){
	scanf("%d%d%d", &n, &l, &r);
	ans[0]=1;
	ll L=0, R=0;
	for(int i=1; i<l; i++) ans[i]=ans[i-1]+ans[i-1];
	for(int i=l; i<n; i++) ans[i]=1;
	for(int i=0; i<n; i++) L+=ans[i];
	
	for(int i=1; i<r; i++) ans[i]=ans[i-1]+ans[i-1];
	for(int i=r; i<n; i++) ans[i]=ans[i-1];
	for(int i=0; i<n; i++) R+=ans[i];
	printf("%lld %lld", L, R);
}