#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
long long a,b,c,d,x[1000000],y[1000000];
int main(){
	cin>>a; y[0]=1000000000000000;
	rep(i,a)cin>>b, c+=b;
	cin>>b;
	if(b==0){
		cout<<-1<<endl;
		return 0;	
	}
	rep(i,b)cin>>x[i]>>y[i];
	if(c>y[b]){
		cout<<-1<<endl;
		return 0;
	}
	rep(i,b){
		if(c>=x[i] && c<=y[i]){
			cout<<c<<endl;
			return 0;
		}else if(x[i]>=c){
			cout<<x[i]<<endl;
			return 0;
		}
	}
}