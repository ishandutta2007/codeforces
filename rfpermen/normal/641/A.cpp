#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
long long II[100001];
char I[100001];
int a,b;
int main(){
	b=0;
	cin>>a;
	rep(i,a)cin>>I[i];
	rep(i,a)cin>>II[i];
	rep(i,1000000){
		if(b<0 || b>=a){
			cout<<"FINITE"<<endl; return 0;
		}
		if(I[b]=='<')b=b-II[b];
		else b=b+II[b];
	}
	cout<<"INFINITE"<<endl;
	return 0;
}