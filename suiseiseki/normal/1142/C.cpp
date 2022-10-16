#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
struct Node{
	ll x,y;
	friend bool operator <(Node p,Node q){
		if(p.x==q.x){
			return p.y>q.y;
		}
		return p.x<q.x;
	}
}a[Maxn+5];
int st[Maxn+5],top;
double slope(int i,int j){
	return 1.0*(a[j].y-a[i].y)/(a[j].x-a[i].x);
}
int n;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].y-=a[i].x*a[i].x;
	}
	sort(a+1,a+1+n);
	a[0].x=a[1].x-1;
	for(int i=1;i<=n;i++){
		if(a[i].x==a[i-1].x){
			continue;
		}
		while(top>1&&slope(st[top-1],st[top])<=slope(st[top-1],i)){
			top--;
		}
		st[++top]=i;
	}
	cout<<max(top-1,0)<<endl;
	return 0;
}