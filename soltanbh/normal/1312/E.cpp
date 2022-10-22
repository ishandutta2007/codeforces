#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1005;
int n,a[2][N],cnt,cn,x;
vector<int> v;
map<vector<int>,int> mp;
int solve(vector<int> v){
	int ans=0;
	vector<int> s1,s2,g1;
	if(v.size()==1) return 1;
	if(v.size()==0) return 0;
	if(mp[v]>0) return mp[v];
	int mn=1e9;
	f(i,0,v.size())
		minm(mn,v[i]);
	f(i,0,v.size()){
		if(v[i]==mn){
			f(j,0,i) s1.pb(v[j]);
			f(j,i+1,v.size()) s2.pb(v[j]);
			ans=solve(s1)+solve(s2)+1;
			if(i<v.size()-1 && v[i+1]==mn){
				f(j,0,i) g1.pb(v[j]);
				g1.pb(v[i]+1);
				f(j,i+2,v.size()) g1.pb(v[j]);
				minm(ans,solve(g1));
			}
			break;
		}
	}
	mp[v]=ans;
	return ans;
}
int main(){
	cin>>n;
	f(i,0,n){cin>>x;v.pb(x);}
	cout<<solve(v);
}