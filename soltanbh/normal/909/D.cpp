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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second

const int N=1e6+99;

int n,t,ans,F[N],P[N];
string s;
set<int> e[N];

void del(int x){
	int next=F[x],prev=P[x];
	if(0<=next){
		P[next]=P[x];
		if((P[next]>-1 && s[next]!=s[P[next]]) || (F[next]>-1 && s[next]!=s[F[next]])){
			e[ans+1].insert(next);
		}
		else
			e[ans+1].erase(next);
	}
	if(0<=prev){
		F[prev]=F[x];
		if((P[prev]>-1 && s[prev]!=s[P[prev]]) || (F[prev]>-1 && s[prev]!=s[F[prev]])){
			e[ans+1].insert(prev);
		}
		else
			e[ans+1].erase(prev);
	}
}
void do_it(){
	while(e[ans].size()){
		int u=*e[ans].begin();
		e[ans].erase(u);
		e[ans+1].erase(u);
		del(u);
	}
}

int main(){
	cin>>s;
	n=s.size();
	if(n==1) return cout<<0,0;
	P[0]=-1,F[0]=1,P[n-1]=n-2,F[n-1]=-1;
	f(i,1,n-1)
		P[i]=i-1,F[i]=i+1;
	f(i,0,n)
		if((P[i]>-1 && s[i]!=s[P[i]]) || (F[i]>-1 && s[i]!=s[F[i]]))
			e[0].insert(i);
	for(;e[ans].size();ans++)
		do_it();
	cout<<ans;
}