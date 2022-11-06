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
const int MOD=1000000007;
#define mult(x,y) (1ll*(x)*(y)%MOD)

const int N = 1000001;
int n,m;
string s;
int T[N];
void make() {
	T[0]=1;
	T[1]=1;
	T[2]=2;
	T[3]=3;
	for(int i=4; i<N; i++) T[i]=(T[i-1]+T[i-2])%MOD;
}
int main(void){
	cin >> s;
	make();
	char prv=-1;
	int num=0;
	ll ans=1;
	for(int i=0; i<sz(s); i++) {
		if(s[i]=='m'||s[i]=='w'){
			printf("0");
			return 0;
		}
	}
	for(int i=0; i<sz(s); i++) {
		if(s[i]!=prv) {
			ans=ans*T[num]%MOD;
			num=0;
		}
		if(s[i]=='n' || s[i]=='u') {
			prv=s[i];
			num++;
		} else {
			prv=-1;
		}
	}
	ans=ans*T[num]%MOD;
	printf("%lld", ans);
}