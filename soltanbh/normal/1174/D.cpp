#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=4e6;
int n,x,mark[N],a;
vector<int> v;
int xoor(int x,int y){
	int ans=0;
	for(int i=0;x || y;i++){
		ans+=(1<<i)*(x%2!=y%2);
		x/=2,y/=2;
	}
	return ans;
}
int main(){
	cin>>n>>x;
	v.pb(0);
	f(i,1,(1<<n)){
		if(i!=x){
			if(mark[min(i,xoor(i,x))]==0){
				mark[min(i,xoor(i,x))]=1;
				v.pb(min(i,xoor(i,x)));
			}
		}
	}
	cout<<v.size()-1<<endl;
	f(i,0,v.size()-1)
		cout<<xoor(v[i+1],v[i])<<" ";
	
}