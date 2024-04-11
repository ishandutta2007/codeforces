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
int x[100][100];

bool check0(){
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!x[i][j]) return false;
		}
	}
	return true;
}
bool check1(){
	bool flag=true;
	for(int i=0; i<n; i++) {
		if(!x[i][0]) {flag=false; break;}
	}
	if(flag) return true;
	flag=true;
	for(int i=0; i<n; i++) {
		if(!x[i][m-1]) {flag=false; break;}
	}
	if(flag) return true;
	flag=true;
	for(int i=0; i<m; i++) {
		if(!x[0][i]) {flag=false; break;}
	}
	if(flag) return true;
	flag=true;
	for(int i=0; i<m; i++) {
		if(!x[n-1][i]) {flag=false; break;}
	}
	if(flag) return true;
	return false;
}
bool check2(){
	if(x[0][0] || x[n-1][m-1] || x[0][m-1] || x[n-1][0]) return true;
	for(int i=1; i<n-1; i++) {
		bool flag=true;
		for(int j=0; j<m; j++) {
			if(!x[i][j]) {flag=false; break;}
		}
		if(flag) return true;
	}
	for(int i=1; i<m-1; i++) {
		bool flag=true;
		for(int j=0; j<n; j++) {
			if(!x[j][i]) {flag=false; break;}
		}
		if(flag) return true;
	}
	return false;
}
bool check3(){
	for(int i=0; i<m; i++) {
		if(x[0][i]) return true;
		if(x[n-1][i]) return true;
	}
	for(int i=0; i<n; i++) {
		if(x[i][0]) return true;
		if(x[i][m-1]) return true;
	}
	return false;
}
bool check4() {
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(x[i][j]) return true;
	return false;
}
void proc() {
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		cin>>s;
		for(int j=0; j<m; j++) x[i][j]=(s[j]=='A');
	}
	if(check0()) {printf("0\n"); return;}
	if(check1()) {printf("1\n"); return;}
	if(check2()) {printf("2\n"); return;}
	if(check3()) {printf("3\n"); return;}
	if(check4()) {printf("4\n"); return;}
	printf("MORTAL\n");
}
int main(void){
	int TC;
	scanf("%d", &TC);
	while(TC--) {
		proc();
	}
}