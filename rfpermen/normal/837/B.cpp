#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
const int MAX=1005;
int n,m,x,y,stat,r,g,b;
char grid[105][105],tmp,vis[3];
int main(){
	//cout<<fixed<<setprecision(9);
	//ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		rep(j,1,m){
			cin>>grid[i][j];
			if(grid[i][j]=='R')r++;
			else if(grid[i][j]=='G')g++;
			else b++;
		}
	}
	if(r!=g||g!=b)return cout<<"NO",0;
	tmp=grid[1][1];
	if(tmp=='R')vis[0]=1;
	else if(tmp=='G')vis[1]=1;
	else if(tmp=='B')vis[2]=1;
	rep(i,1,n){
		if(tmp!=grid[i][1])break;
		else if(i==n)stat=1;
	}
	rep(i,1,m){
		if(tmp!=grid[1][i])break;
		else if(i==m && stat){
			cout<<"NO"<<endl;
			return 0;
		}
		else if(i==m)stat=2;
	}
	if(stat==0){
		cout<<"NO"<<endl;
		return 0;
	}
	if(stat==1){
		rep(j,1,m){
			if(tmp!=grid[1][j])break;
			rep(i,1,n){
				if(tmp!=grid[i][j]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
			x++;
		}
		if(m%x!=0 && m/3!=x){
			cout<<"NO"<<endl;
			return 0;
		}
		tmp=grid[1][x+1];
		if(tmp=='R')vis[0]=1;
		else if(tmp=='G')vis[1]=1;
		else if(tmp=='B')vis[2]=1;
		rep(j,x+1,2*x){
			rep(i,1,n){
				if(tmp!=grid[i][j]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		tmp=grid[1][2*x+1];
		if(tmp=='R')vis[0]=1;
		else if(tmp=='G')vis[1]=1;
		else if(tmp=='B')vis[2]=1;
		rep(j,2*x+1,m){
			rep(i,1,n){
				if(tmp!=grid[i][j]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		rep(i,0,2){
			if(vis[i]==0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
		return 0;
	}
	else {
		rep(i,1,n){
			if(tmp!=grid[i][1])break;
			rep(j,1,m){
				if(tmp!=grid[i][j]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
			x++;
		}
		if(n%x!=0 && n/3!=x){
			cout<<"NO"<<endl;
			return 0;
		}
		tmp=grid[x+1][1];
		if(tmp=='R')vis[0]=1;
		else if(tmp=='G')vis[1]=1;
		else if(tmp=='B')vis[2]=1;
		rep(i,x+1,2*x){
			rep(j,1,m){
				if(tmp!=grid[i][j]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		tmp=grid[2*x+1][1];
		if(tmp=='R')vis[0]=1;
		else if(tmp=='G')vis[1]=1;
		else if(tmp=='B')vis[2]=1;
		rep(i,2*x+1,n){
			rep(j,1,m){
				if(tmp!=grid[i][j]){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		rep(i,0,2){
			if(vis[i]==0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
		return 0;
	}
	return 0;
}