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
string ans;
string ans2;
string split(int loc) {
	string s1=s.substr(0, loc);
	string s2=s.substr(loc);
	reverse(all(s1)); reverse(all(s2));
	if(sz(s1)<sz(s2)) swap(s1, s2);

	int cur=0;
	for(int i=0; i<sz(s1); i++) {
		cur+=s1[i]-'0';
		if(i<sz(s2)) cur+=s2[i]-'0';
		if(cur<10) s1[i]='0'+cur, cur=0;
		else s1[i]='0'+cur-10, cur=1;
	}
	if(cur==1) {
		s1.append("1");
	}
	reverse(all(s1));
	return s1;
}
bool cmp() {
	if(sz(ans)<sz(ans2)) return true;
	if(sz(ans)>sz(ans2)) return false;

	for(int i=0; i<sz(ans); i++) {
		if(ans[i]<ans2[i]) return true;
		if(ans[i]>ans2[i]) return false;
	}
	return true;
}
int main(void){
	scanf("%d", &n);
	cin >> s;

	int l=n/2, r=(n+1)/2;
	while(r<n && s[r]=='0') r++;
	while(l>0 && s[l]=='0') l--;
	if(r<n) ans=split(r);
	if(l>0) ans2=split(l);

	if(ans=="") cout<<ans2;
	else if(ans2=="") cout<<ans;
	else {
		if(cmp()) cout << ans;
		else cout << ans2;
	}
}