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
string s;

bool f(int l, int r) {
	for(int i=l; i<=r; i++)
		for(int j=i+2; j<=r; j+=2) {
			if(s[i]==s[j] && s[i]==s[(i+j)/2]) return true;
		}
	return false;
}

int main(void){
	cin >> s;
	n=sz(s);
	ll cnt=0;
	if(n>8) cnt=1ll*(n-8)*(n-7)/2;

	for(int d=0; d<=7; d++) {
		for(int i=0,j=d; j<n; i++,j++) {
			if(f(i,j)) cnt++;
		}
	}
	cout << cnt;
}