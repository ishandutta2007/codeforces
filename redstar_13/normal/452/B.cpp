#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
#define rt(x) (x)*(x)
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1 and m==1){
		cout<<1<<' '<<1<<endl;
		cout<<0<<' '<<0<<endl;
		cout<<1<<' '<<0<<endl;
		cout<<0<<' '<<1<<endl;
		return 0;
	}
	if(n==0){
		
		cout<<0<<" "<<1<<endl;
		cout<<0<<" "<<m<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<0<<" "<<m-1<<endl;
		return 0;
	}
	if(m==0){
		cout<<1<<" "<<0<<endl;
		cout<<n<<" "<<0<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<n-1<<" "<<0<<endl;
		return 0;
	}
	if(n>m){
		double a=2.0*sqrt(rt(n)+rt(m-1));
		double b=(double)sqrt(rt(n)+rt(m))+n;
		if(a<b){
			cout<<0<<" "<<0<<endl;
			cout<<n<<" "<<m<<endl;
			cout<<0<<" "<<m<<endl;
			cout<<n<<" "<<0<<endl;
			return 0;
		}
		else{
			cout<<0<<" "<<m-1<<endl;
			cout<<n<<" "<<0<<endl;
			cout<<0<<" "<<m<<endl;
			cout<<n<<" "<<1<<endl;
			return 0;
		}
	}
	else {
		double a=2.0*sqrt(rt(m)+rt(n-1));
		double b=(double)sqrt(rt(m)+rt(n))+m;
		if(a<b){
			cout<<0<<" "<<0<<endl;
			cout<<n<<" "<<m<<endl;
			cout<<n<<" "<<0<<endl;
			cout<<0<<" "<<m<<endl;
			return 0;
		}
		else {
			cout<<1<<" "<<0<<endl;
			cout<<n<<" "<<m<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<n-1<<" "<<m<<endl;
			return 0;
		}
	}
}