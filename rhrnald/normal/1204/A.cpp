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
int main(void){
	cin >> s;
	n=sz(s);

	bool flag=true;
	for(int i=1; i<n; i++) if(s[i]=='1') {flag=false; break;}
	if(!(n&1)) flag=false;

	cout << (n+1)/2-flag << endl;
}