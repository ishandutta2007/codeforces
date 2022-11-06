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

char s[N];
int cnt[N];

ll f(int x) {
	return 1ll*x*(x-1)/2;
}
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s", s);
		cnt[s[0]-'a']++;
	}

	ll ans=0;
	for(int i=0; i<26; i++) {
		int m1=cnt[i]/2;
		int m2=cnt[i]-m1;
		ans+=f(m1)+f(m2);
	}
	cout << ans;
}