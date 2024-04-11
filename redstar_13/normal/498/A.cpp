#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
#endif
	int n;
	double x1,x2,y1,y2,a,b,c;
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	int t=0;
	while(n--){
		cin>>a>>b>>c;
		if((a*x1+b*y1+c)*(a*x2+b*y2+c)<0) t++;
	}
	cout<<t<<endl;
}