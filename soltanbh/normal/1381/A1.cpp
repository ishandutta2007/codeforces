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

int n,t;
string a,b;
vector<int> ans;

void change(int x){
	f(i,0,x){
		if(a[i]=='1') a[i]='0';
		else a[i]='1';
	}
	f(i,0,x/2)
		swap(a[i],a[x-1-i]);
}
void do_it(){
	if(a[n-1]==b[n-1]) return ;
	if(a[0]==b[n-1]){ ans.pb(1),ans.pb(n); change(1);change(n); }
	else change(n),ans.pb(n);
}
int main(){
	cin>>t;
	while(t--){
		ans.clear();
		cin>>n;
		cin>>a>>b;
		while(n){
			do_it();
			n--;
		}
		cout<<ans.size()<<endl;
		f(i,0,ans.size()) cout<<ans[i]<<" "; cout<<endl;
	}
}