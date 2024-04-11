#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	long long a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if((b-d)*(c-e)-(a-c)*(d-f)==0)cout<<"No"<<endl;
	else{
		if((long long)((c-a)*(c-a)+(d-b)*(d-b))==(long long)((c-e)*(c-e)+(d-f)*(d-f)))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}	
	
	return 0;
}