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
const int MOD = 998244353;
int n,m,cnt;
 
int sum[20];
int num[20];
ll pw[40];
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &m);
		for(cnt=0; m; cnt++, m/=10) sum[cnt]+=m%10;
		num[cnt]++;
	}
	pw[0]=1;
	for(int i=1; i<=30; i++) pw[i]=pw[i-1]*10%MOD;
	ll ans=0;
 
	for(int i=0; i<20; i++)
		for(int j=1; j<20; j++) {
			ans=(ans+(1ll*sum[i]*num[j])%MOD*(pw[min(i+1,j)+i]+pw[min(i,j)+i])%MOD)%MOD;
		}
	cout << ans;
}