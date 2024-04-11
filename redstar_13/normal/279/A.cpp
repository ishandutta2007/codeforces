#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int x,y,s;
	cin>>x>>y;
	if(x==0 and y==0) s=0;
	else{
		s=(max(abs(x),abs(y))-1)*4;
		if((x-y)>=0 and (x+y-1)>0){s++;if(0<x and x<=1 and y==0)s--;}
		else if((x-y)<0 and (x+y)>=0)s+=2;
		else if((x-y)<=0 and (x+y)<0)s+=3;
		else if((x-y)>0 and (x+y)<=0)s+=4;
	}
		cout<<s<<endl;
	return 0;
}