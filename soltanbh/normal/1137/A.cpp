#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1002;

int n,m,p,t,x,a[N][N],ans1[N][N],ans2[N][N];

vector<pair<int,int> > col[N],row[N];

int main(){
	cin>>n>>m;
	f(i,0,n){
		f(j,0,m){
			gett(x);
			col[j].pb(mp(x,i));
			row[i].pb(mp(x,j));
		}
	}
	f(i,0,n){
		sort(row[i].begin(),row[i].end());
		p=0;
		f(j,0,row[i].size()){
			if(j!=0 && row[i][j-1].F!=row[i][j].F) p++;
			maxm(ans1[i][row[i][j].S],p);
		}
		p=0;
		f_(j,row[i].size()-1,0){
			if(j!=row[i].size()-1 && row[i][j].F!=row[i][j+1].F) p++;
			maxm(ans2[i][row[i][j].S],p);
		}
	}
	f(i,0,m){
		sort(col[i].begin(),col[i].end());
		p=0;
		f(j,0,col[i].size()){
			if(j!=0 && col[i][j-1].F!=col[i][j].F) p++;
			maxm(ans1[col[i][j].S][i],p);
		}
		p=0;
		f_(j,col[i].size()-1,0){
			if(j!=col[i].size()-1 && col[i][j].F!=col[i][j+1].F) p++;
			maxm(ans2[col[i][j].S][i],p);
		}
	}
	f(i,0,n){
		f(j,0,m)
			cout<<ans1[i][j]+ans2[i][j]+1<<" ";
		cout<<endl;
	}
}