#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t,n,m,l[100099],x,cost,mx;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>m;cost=0;
		f(i,1,n+1){
			cin>>x;
			l[x]=i;
		}
		mx=0;
		f(i,1,m+1){
			cin>>x;
			if(l[x]>mx){
				mx=l[x];
				cost+=(l[x]-i)*2+1;
			}
			else
				cost++;
		}
		cout<<cost<<endl;
	}
}