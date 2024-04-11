#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	int x;
	cin>>s>>x;
	if (s=="AGC"&&x<1200||s=="ABC"&&x>=2000||s=="ARC"&&x>=2800) cout<<"No\n"; else cout<<"Yes\n";
}