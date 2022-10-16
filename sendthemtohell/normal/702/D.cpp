#include<bits/stdc++.h>
//#include<iostream>


using namespace std;

int main(){
	int long long d,k,a,b,t,res=0;
	cin>>d>>k>>a>>b>>t;
	if(b<=a){
		cout<<d*b<<endl;
		return 0;
	}
	res+=min(a*k,d*a);
	d-=min(d,k);
	//res+=min(a*k,d*a);
	//cout<<"   "<<res<<endl;
	if(d==0){
		cout<<res<<endl;
		return 0;
	}
	if(d>k){
		if(b*k<=a*k+t){
			cout<<res+b*d<<endl;
			return 0;
		}
		int long long e=d/k;
		d%=k;
		res+=(a*k+t)*e;
	}
	cout<<res+min(b*d,a*d+t)<<endl;
	return 0;
}