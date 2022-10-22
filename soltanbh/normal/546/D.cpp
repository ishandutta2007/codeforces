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

const int N=5e6+99;

int n,t,a,b,mark[N];

int main(){
	f(i,2,N)
		if(mark[i]==0)
			for(int j=i;j<N;j+=i){
				int c=j;
				while(c%i==0)
					mark[j]++,c/=i;
			}
	f(i,1,N) mark[i]+=mark[i-1];
	cin>>t;
	while(t--){
		Gett(a,b);
		printf("%d\n",mark[a]-mark[b]);
	}
}