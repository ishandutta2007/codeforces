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
 
const int N = 3300001;
const int MOD=1000000007;
int xx;
int x[N];
string s;
void proc() {
	scanf("%d", &xx);
	cin >> s;
	ll len=sz(s);
	for(int i=0; i<len; i++) x[i]=s[i]-'0';
	bool flag=true;
	for(int i=0; i<xx; i++) {
		if(flag) {
			ll cur=len;
			for(int k=0; k<x[i]-1; k++) {
				for(ll j=i+1; j<=cur-1; j++) {
					x[len]=x[j];
					len++;
				}
			}
			if(len>=xx) flag=false;
		} else {
			len=(((len-i-1)*x[i]+i+1)%MOD+MOD)%MOD;
		}
	}
	printf("%lld\n", len);
}
int main(void){
	int TC;
	scanf("%d", &TC);
	while(TC--) proc();
}