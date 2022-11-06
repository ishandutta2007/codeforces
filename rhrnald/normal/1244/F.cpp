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
int n;
ll k;
string s;
int x[N];
int y[N];
int main(void){
	scanf("%d%lld", &n, &k);
	cin >> s;
	for(int i=0; i<n; i++) {
		if(s[i]=='B') x[i]=1;
		else x[i]=2;
	}
	x[n]=x[0];

	for(int i=1; i<=n; i++) {
		if(x[i]==x[i-1]) y[i]=x[i];
	} y[0]=y[n];
	for(int i=0; i<n; i++) {
		if(x[i]==x[i+1]) y[i]=x[i];
	} y[n]=y[0];

	for(int i=n; i<=n+n; i++) x[i]=x[i-n];
	for(int i=n; i<=n+n; i++) y[i]=y[i-n];

	int st=-1;
	for(int i=0; i<n; i++) {
		if(y[i]) {st=i; break;}
	}
	if(st<0) {
		if(k%2) {
			for(int i=0; i<n; i++) {
				if(s[i]=='B') printf("W");
				else printf("B");
			}
		} else {
			cout << s;
		}
		return 0;
	}

	for(int i=st; i<st+n; i++) {
		if(y[i]) continue;
		int l=i;
		while(!y[i]) i++;
		int r=i-1;
		if(!((l-r)%2)) {//BBWBWBB
			int num=(r-l)/2+1;
			if(k>=num) {
				for(int j=l; j<=r; j++) y[j]=y[l-1];
			} else {
				for(int j=l; j<l+k; j++) y[j]=y[l-1];
				for(int j=r; j>r-k; j--) y[j]=y[r+1];
				for(int j=l+k; j<=r-k; j++) y[j]=3-y[j-1];
			}
		} else {//BBWBWW
			int num=(r-l+1)/2;
			if(k>=num) {
				for(int j=l; j<l+num; j++) y[j]=y[l-1];
				for(int j=r; j>r-num; j--) y[j]=y[r+1];
			} else {
				for(int j=l; j<l+k; j++) y[j]=y[l-1];
				for(int j=r; j>r-k; j--) y[j]=y[r+1];
				for(int j=l+k; j<=r-k; j++) y[j]=3-y[j-1];
			}

		}
	}
	for(int i=n; i<st+n; i++) y[i-n]=y[i];
	for(int i=0; i<n; i++) {
		if(y[i]==1) printf("B");
		else printf("W");
	}
}