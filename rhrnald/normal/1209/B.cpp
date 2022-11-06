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

const int N = 2001;
int n,m;
string s;
int c[N], a[N], b[N];

int cnt[N];
bool cur[N];
int main(void){
	scanf("%d", &n);
	cin >> s;
	for(int i=0; i<n; i++) c[i]=s[i]=='1';
	for(int i=0; i<n; i++) scanf("%d%d", a+i, b+i);

	for(int i=0; i<n; i++) {
		for(int j=0; j<1000; j++) cur[j]=false;
		for(int j=b[i]; j<1000; j+=a[i]) cur[j]=true;
		for(int j=0; j<1000; j++) {
			if(cur[j]) c[i]=!c[i];
			if(c[i]) cnt[j]++;
		}
	}
	int M=0;
	for(int i=0; i<1000; i++) M=max(M, cnt[i]);
	printf("%d", M);
}