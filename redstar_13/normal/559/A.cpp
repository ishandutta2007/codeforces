#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int s=(a+b+c)*(a+b+c)-a*a-e*e-c*c;
	cout<<s<<endl;
	
	
	return 0;
}