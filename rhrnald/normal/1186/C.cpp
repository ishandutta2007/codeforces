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
string s, t;
int x[N];
int main(void){
	cin >> s >> t;
	n=s.size();
	m=t.size();
	int cnt=0;
	for(int i=0; i<n; i++) x[i]=s[i]=='0';
	for(int i=1; i<n; i++) x[i]+=x[i-1];
	for(int i=0; i<m; i++) if(t[i]=='0') cnt++;

	
	int a=0, b=0;
	for(int i=0; i+m<=n; i++) {
		if((x[i+m-1]-(i?x[i-1]:0)+cnt)&1) a++;
		else b++;
	}
	cout << b;
}