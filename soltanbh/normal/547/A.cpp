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
 
const int N=1e6+2;
 
ll m,h1,a1,x1,yy1,h2,a2,x2,y2,b1,m1,b2,m2,s1,s2,mark[N];
pair<ll,pair<ll,ll> > p;
map<ll,ll> maap;
 
void solve(int h,int a,int x,int y){
	int n=h;
	mark[h]=1;
	pair<int,pair<int,int> > ans;
	for(int i=1;1;i++){
		n=(1ll*n*x+y)%m;
		if(i>2*m){
			if(mark[a]){
				maap[mark[a]-1]++;
				if(maap[mark[a]-1]==2){
					cout<<mark[a]-1;
					exit(0);
				}
			}
			else{
				cout<<-1;
				exit(0);
			}
			return ;
		}
		if(n==a){
			if(mark[a]>0){
				f(j,0,m){
					maap[mark[a]-1+j*(i-mark[a]+1)]++;
					if(maap[mark[a]-1+j*(i-mark[n]+1)]==2){
						cout<<mark[a]+j*(i-mark[n]+1)-1<<endl;
						exit(0);
					}
				}
				return ;
			}
			else
				mark[n]=i+1;
		}
	}
}
int main(){
	cin>>m>>h1>>a1>>x1>>yy1>>h2>>a2>>x2>>y2;
	if(a1==h1 && a2==h2) return cout<<1,0;
	solve(h1,a1,x1,yy1);
	fill(mark,mark+N,0);
	solve(h2,a2,x2,y2);cout<<-1;
}