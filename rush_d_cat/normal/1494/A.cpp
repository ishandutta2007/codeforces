#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
bool check(string s) {
	int x=0;
	for(int i=0;s[i];i++) {
		if(s[i]=='(') x++;
		else x--;
		if(x<0)return 0;
	}
	return x==0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t --) {
		string s; cin>>s;
		bool ok=0;
		for(int mask=0;mask<8;mask++) {
			string ss=s;
			for(int i=0;s[i];i++)
				if(mask>>(s[i]-'A')&1) ss[i]='('; else ss[i]=')';
			ok |= check(ss);
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}