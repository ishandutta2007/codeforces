#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=305;

int n,m,a[N][N],t;

int adj(int x,int y){
	int res=4;
	if(x==0 || x==n-1) res--;
	if(y==0 || y==m-1) res--;
	return res;
}
int main(){
	cin>>t;
	f(q,0,t){
		int ans=1;
		cin>>n>>m;
		f(i,0,n)
			f(j,0,m){
				cin>>a[i][j];
				if(adj(i,j)<a[i][j])
					ans=0;
			}
		if(!ans) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			f(i,0,n){
				f(j,0,m)
					cout<<adj(i,j)<<" ";
				cout<<endl;
			}
		}
	}
}