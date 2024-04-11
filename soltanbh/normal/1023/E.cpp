#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,x,y,m;
string s,s1,s2;

bool ask(int a,int b,int c,int d){
	cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	cin>>s;
	return s[0]=='Y';
}

int main(){
	cin>>n;
	x=1,y=1;
	while(x+y<n+1){
		if(ask(x+1,y,n,n))
			x++,s1+='D';
		else
			y++,s1+='R';
	}
	x=n,y=n;
	while(x+y>n+1){
		if(ask(1,1,x,y-1))
			y--,s2+='R';
		else
			x--,s2+='D';
	}
	cout<<"! "<<s1;
	f_(i,s2.size()-1,0)
		cout<<s2[i];
}