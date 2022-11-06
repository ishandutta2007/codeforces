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
void proc() {
	scanf("%d%d", &n, &m);
}
string s;
int x[N];
int sum[N];

ll ans;
vector<int> v;
int main(void){
	cin>>s;
	n=sz(s);
	for(int i=0; i<n; i++) x[i+1]=s[i]=='1';
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+x[i];
	for(int k=1; k<=1000; k++) {
		vector<int> v;
		for(int i=0; i<=n; i++)	v.push_back(sum[i]*k-i);
		sort(all(v));

		int cur=1;
		for(int i=1; i<sz(v); i++) {
			if(v[i]==v[i-1]) cur++;
			else {
				ans+=1ll*cur*(cur-1)/2;
				cur=1;
			}
		}
		ans+=1ll*cur*(cur-1)/2;
	}
	
	for(int i=1; i<=n; i++) if(x[i]) v.push_back(i);
	v.push_back(n+1);
	int idx=0;

	for(int i=1; i<=n; i++) {
		while(v[idx]<i) idx++;
		for(int k=1; k<=200 && idx+k<sz(v); k++) {
//			v[idx+k-1]<= <v[idx+k];  k   1000 
			int l=(v[idx+k-1]-i)/k+1;
			int r=(v[idx+k]-i)/k;
			l=max(l, 1001);
			r=max(r, 1000);
			ans+=r-l+1;
		}
	}
	printf("%lld", ans);
}