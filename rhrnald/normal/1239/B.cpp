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
string s;
int x[N];
vector<int> v;
int main(void){
	scanf("%d", &n);
	cin >> s;
	for(int i=0; i<n; i++) {
		if(s[i]=='(') x[i+1]=x[i]+1;
		else x[i+1]=x[i]-1;
	}
	if(x[n]!=0) {
		printf("0\n 1 1");
		return 0;
	}

	for(int i=0; i<n; i++) x[i+n]=x[i];

	m=0;
	for(int i=0; i<n; i++) m=min(m, x[i]);

	int cnt=0;
	for(int i=0; i<n; i++) if(x[i]==m) v.push_back(i),  cnt++;
	v.push_back(v[0]+n);
	int ans=0, l=1, r=1;
	for(int i=0; i<sz(v)-1; i++) {
		int t=0;
		for(int j=v[i]; j<=v[i+1]; j++)	if(x[j]==m+1) t++;
		if(t>ans) ans=t, l=v[i]+1, r=v[i+1];
	}
	v.clear();

	for(int i=0; i<n; i++) if(x[i]<=m+1) v.push_back(i);
	v.push_back(v[0]+n);

	for(int i=0; i<sz(v)-1; i++) {
		int t=0;
		for(int j=v[i]; j<=v[i+1]; j++)	if(x[j]==m+2) t++;
		if(t+cnt>ans) ans=t+cnt, l=v[i]+1, r=v[i+1];
	}
	if(l>n) l-=n;
	if(r>n) r-=n;
	printf("%d\n%d %d", ans, l, r);
}