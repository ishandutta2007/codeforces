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
vector<vector<int>> v;
vector<vector<int>> cnt, cnt2;
int main(void){
	scanf("%d%d", &n, &m);
	v=vector<vector<int>>(n,vector<int>(m,0));
	cnt=vector<vector<int>>(n,vector<int>(m,0));
	cnt2=vector<vector<int>>(n,vector<int>(m,0));
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0;j<m;j++) {
			v[i][j]=s[j]=='.';
		}
	}
	cnt[0][0]=1;cnt2[n-1][m-1]=1;
	for(int i=1; i<m; i++) {
		if(v[0][i]) cnt[0][i]=1;
		else break;
	}
	for(int i=m-2; i>=0; i--) {
		if(v[n-1][i]) cnt2[n-1][i]=1;
		else break;
	}
	for(int i=1; i<n; i++) {
		if(v[i][0]) cnt[i][0]=1;
		else break;
	}
	for(int i=n-2; i>=0; i--) {
		if(v[i][m-1]) cnt2[i][m-1]=1;
		else break;
	}

	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			if(v[i][j]) cnt[i][j]=cnt[i-1][j] || cnt[i][j-1];
		}
	}
	for(int i=n-2; i>=0; i--) {
		for(int j=m-2; j>=0; j--) {
			if(v[i][j]) cnt2[i][j]=cnt2[i+1][j] || cnt2[i][j+1];
		}
	}

	if(cnt[n-1][m-1]==0) {printf("0"); return 0;}
	for(int s=1; s<=n+m-3; s++) {
		int c=0;
		for(int i=max(0, s-m+1); i<min(s+1,n); i++) {
			int j=s-i;
			if(cnt[i][j] && cnt2[i][j]) c++;
		}
		if(c==1) {printf("1"); return 0;}
	}
	printf("2"); return 0;
}