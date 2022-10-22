#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,g[N][2],mark[N];
pair<int,int> a[N];
int main(){
	cin>>t;
	while(t--){
		int ans=1;
		f(i,0,n+2) mark[i]=0;
		cin>>n;
		set<int> s;
		f(i,0,n) {gett(a[i].F);a[i].S=i;}
		sort(a,a+n);
		f(i,0,n) s.insert(1),g[i][0]=i-1,g[i][1]=i+1,mark[1]++;
		f(i,0,n){
			int mx=*s.rbegin();
		//	cout<<g[a[i].S][0]<<endl;
		//	cout<<a[i].S-g[a[i].S][0]<<" "<<mx<<endl;
			if(a[i].S-g[a[i].S][0]!=mx){ ans=0;break;}
			mark[mx]--;
			if(mark[mx]==0) s.erase(mx);
			if(g[a[i].S][1]!=n){
				mx=g[a[i].S][1]-a[i].S;
				mark[mx]--;
			}
			if(mark[mx]==0) s.erase(mx);
			if(g[a[i].S][1]!=n){
				s.insert(g[a[i].S][1]-g[a[i].S][0]),mark[g[a[i].S][1]-g[a[i].S][0]]++;
			}
			g[g[a[i].S][1]][0]=g[a[i].S][0];
			g[g[a[i].S][0]][1]=g[a[i].S][1];
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}