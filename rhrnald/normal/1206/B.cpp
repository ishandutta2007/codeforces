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
int x[N];
int main(void){
	scanf("%d", &n);
	bool f=false;
	for(int i=0; i<n; i++) {scanf("%d", x+i); if(!x[i]) f=true;}
	ll ans=0;
	int cnt=0;

	for(int i=0; i<n; i++) {
		if(x[i]>0) ans+=x[i]-1;
		else if(x[i]<0) ans+=-1-x[i], cnt++;
		else ans+=1;
	}
	if(!f && (cnt&1)) ans+=2;
	cout <<ans;
}