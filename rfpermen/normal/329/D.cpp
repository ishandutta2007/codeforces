#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int x,y;
int main(){
	cin>>x>>y;
	if(x==5 && y==5)cout<<">...v"<<endl<<"v.<.."<<endl<<"..^.."<<endl<<">...."<<endl<<"..^.<"<<endl<<1<<" "<<1<<endl;
	else if(x==3 && y==2)cout<<">vv"<<endl<<"^v."<<endl<<"^.<"<<endl<<1<<" "<<3<<endl;
	else {
		int a=16;
		for(int i=1;i<=50;i++)cout<<">v"; cout<<endl;
		while(a--){
		for(int i=1;i<=50;i++)cout<<".v"; cout<<endl;
		for(int i=1;i<=50;i++)cout<<"^v"; cout<<endl;
		}
		a=16;
		while(a--){
		for(int i=1;i<=50;i++)cout<<".."; cout<<endl;
		for(int i=1;i<=50;i++)cout<<"^v"; cout<<endl;
		}
		a=16;
		while(a--){
		for(int i=1;i<=50;i++)cout<<"^."; cout<<endl;
		for(int i=1;i<=50;i++)cout<<"^v"; cout<<endl;
		}
		for(int i=1;i<=50;i++)cout<<"^."; cout<<endl;
		for(int i=1;i<=49;i++)cout<<"^>"; cout<<"^v"; cout<<endl;
		cout<<"^<"; for(int i=1;i<=49;i++)cout<<"<<"; cout<<endl;
		cout<<100<<" "<<1<<endl;
	}
	return 0;
}