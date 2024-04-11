#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
long long a,b,c,d,e,f,g,h,idx,z[200002][2],Z[200002][2];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a; idx=0, c=1000000001, e=1000000001, d=0, f=0;
	rep(i,a)cin>>z[i][0]>>z[i][1];
	cin>>b;
	rep(i,b)cin>>Z[i][0]>>Z[i][1];
	rep(i,a){
		if(d<z[i][0])d=z[i][0];
		if(c>z[i][1])c=z[i][1];
	}
	rep(i,b){
		if(f<Z[i][0])f=Z[i][0];
		if(e>Z[i][1])e=Z[i][1];	
	}
	g=f-c, h=d-e;
	//cout<<c<<d<<f<<e<<endl;
	if((g>h)&&g>0)cout<<g<<endl;
	else if(h>0)cout<<h<<endl;
	else cout<<0<<endl;
	return 0;
}