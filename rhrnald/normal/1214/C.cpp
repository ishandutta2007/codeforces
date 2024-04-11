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
string s,s1,s2;

bool check(string &s) {
	int cnt=0;
	for(int i=0; i<n; i++) {if(s[i]=='(') cnt++; else cnt--; if(cnt<0) return false;}
	return true;
}
int main(void){
	scanf("%d", &n);
	cin >> s;

	int cnt=0;
	for(int i=0; i<n; i++) {if(s[i]==')') cnt++; else cnt--;}
	if(cnt) {printf("No"); return 0;}
	if(check(s)) {printf("Yes"); return 0;}

	for(int i=0; i<n; i++) {
		if(s[i]==')') {
			s1=s;
			for(int j=i; j<n; j++) s1[j]=s1[j+1];
			s1[n-1]=')';
			break;
		}
	}
	if(check(s1)) {printf("Yes"); return 0;}
	for(int i=n-1; i>=0; i--) {
		if(s[i]=='(') {
			s2=s;
			for(int j=i; j>0; j--) s2[j]=s2[j-1];
			s2[0]='(';
			break;
		}
	}
	if(check(s2)) {printf("Yes"); return 0;}

	printf("No");
}