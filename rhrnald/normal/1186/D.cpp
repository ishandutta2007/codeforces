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
int x[N], y[N];
int a[N], b[N];
char s[20];
int main(void){
	scanf("%d", &n);
	ll sum=0;
	for(int i=0; i<n; i++) {
		scanf("%s", s);
		bool t;
		t=s[0]=='-';
		int cur=0;
		if(t) cur++;

		while('0'<=s[cur] && s[cur]<='9') x[i]=x[i]*10+s[cur++]-'0';
		cur++;
		while('0'<=s[cur] && s[cur]<='9') y[i]=y[i]*10+s[cur++]-'0';
		if(t) x[i]=-x[i];
		if(y[i]) {
			if(!t) a[i]=x[i], b[i]=x[i]+1;
			else a[i]=x[i]-1, b[i]=x[i];
		} else {
			a[i]=x[i], b[i]=x[i];
		}
		sum+=a[i];
	}

	int cur=0;
	while(sum) {
		if(b[cur]>a[cur]) a[cur]=b[cur], sum++;
		cur++;
	}
	for(int i=0; i<n; i++) printf("%d\n", a[i]);
}