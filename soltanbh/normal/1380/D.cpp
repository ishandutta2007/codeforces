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
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

ll n,m,x,y,k,a[N],b[N],maxi,num,ind,ans;

int main(){
	cin>>n>>m;
	cin>>x>>k>>y;
	
	f(i,0,n) cin>>a[i];
	f(i,0,m) cin>>b[i];
	n++;
	m++;
	f(i,0,m){
		maxi=num=0;
		while(ind<n && b[i]!=a[ind]){
			num++;
			maxi=max(maxi,a[ind]);
			ind++;
	 	}
		if(ind==n){
			cout<<"-1\n";
			return 0;
		}
		if(num!=0){
			ans+=y*(num%k);
			num-=num%k;
			if(num==0){
				if(maxi>b[i] && (i==0 || maxi>b[i-1])){
					cout<<"-1\n";
					return 0;
				}
			}
			else{
				ans+=min(x*(num/k-1),y*(num/k-1)*k);
				
				if(maxi>b[i] && (i==0 || maxi>b[i-1])){
					ans+=x;
				}
				else ans+=min(x,k*y);
			}
		}
		ind++;
	}
	cout<<ans<<"\n";
}