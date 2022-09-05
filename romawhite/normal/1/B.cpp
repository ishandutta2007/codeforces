//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const double pi=3.141592653589793;
const int INF=1000000000;
const LL pr=1000000007ll;

typedef vector<int> lnum;
const int base = 1000*1000*1000;

void print(lnum a){
	printf ("%d", a.empty() ? 0 : a.back());
	for (int i=(int)a.size()-2; i>=0; --i)
		printf ("%09d", a[i]);
}

lnum read(string s){
	lnum a;
	for (int i=(int)s.length(); i>0; i-=9)
		if (i < 9)
			a.push_back (atoi (s.substr (0, i).c_str()));
		else
			a.push_back (atoi (s.substr (i-9, 9).c_str()));
	return a;
}

lnum mult(lnum a,int b){
	int carry = 0;
	for (size_t i=0; i<a.size() || carry; ++i) {
		if (i == a.size())
			a.push_back (0);
		long long cur = carry + a[i] * 1ll * b;
		a[i] = int (cur % base);
		carry = int (cur / base);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

lnum div(lnum a,int b){
	int carry = 0;
	for (int i=(int)a.size()-1; i>=0; --i) {
		long long cur = a[i] + carry * 1ll * base;
		a[i] = int (cur / b);
		carry = int (cur % b);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

lnum sub(lnum a,lnum b){
	int carry = 0;
	for (size_t i=0; i<b.size() || carry; ++i) {
		a[i] -= carry + (i < b.size() ? b[i] : 0);
		carry = a[i] < 0;
		if (carry)  a[i] += base;
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

bool comp(lnum a,lnum b){
	if (a.size() < b.size()) return 1;
	if (a.size() > b.size()) return 0;
	RFOR(i,a.size(),0){
		if (a[i] < b[i]) return 1;
		if (a[i] > b[i]) return 0;
	}
	return 1;
}

bool f(lnum a){
	if (a.size() == 1 && a[0] == 0) return 0;
	return 1;
}


int main(){
	int n;
	cin >> n;
	FOR(t,0,n){
		string s;
		cin >> s;
		int k;
		if (s[0] != 'R' || (s[1]>'9' || s[1]<'0')) k = 1;
		else{
			int i = 1;
			while (i < s.size() && (s[i]<='9' && s[i]>='0')) ++i;
			if (i == s.size()) k = 1;
			else k = 2;
		}
		if (k == 1){
			cout << 'R';
			int j = 0;
			int ans = 0;
			while (s[j]>='A' && s[j]<='Z'){
				ans *= 26;
				ans += s[j] - 'A' + 1;
				++j;
			}
			FOR(i,j,s.size())
				cout << s[i];
			cout << 'C';
			cout << ans << endl;
		}
		else{
			int r = 0;
			int i = 1;
			while (s[i] != 'C'){
				r *= 10;
				r += s[i] - '0';
				++i;
			}
			int c = 0;
			FOR(j,i+1,s.size()){
				c *= 10;
				c += s[j] - '0';
			}
			string ans = "";

			while(c){
				ans = char('A' + (c - 1 + 26)%26) + ans;
				c = (c - 1)/26;
			}
			cout << ans << r << endl;
		}
	}
}