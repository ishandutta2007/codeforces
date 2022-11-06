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
int cnt[N];
int Mcnt[N], mcnt[N];
bool pos[N];
string s;
int main(void){
	cin >> s;
	int n=sz(s);
	int sum=0;
	for(int i=0; i<n; i++) {
		if(s[i]=='0') sum++;
		else sum--;
		cnt[i]=sum;
	}

	Mcnt[n-1]=cnt[n-1];
	for(int i=n-2; i>=0; i--) Mcnt[i]=max(cnt[i],Mcnt[i+1]);

	for(int i=0; i<n; i++) {
		if(s[i]=='1') {
			if(cnt[i]>=Mcnt[i]) printf("0");
			else printf("1");
		} else printf("0");
	}
}