#include<bits/stdc++.h>
using namespace std;
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
const int MAX=25;
char grid[MAX][MAX];
int cnt;
int main(){
	rep(r,6,15){
		rep(c,6,15)cin>>grid[r][c];
	}
	rep(r,6,15){
		rep(c,6,15){
			if(grid[r][c]=='.'){
				grid[r][c]='X';
				rep(i,r-4,r){
					cnt=0;
					rep(j,i,i+4)if(grid[j][c]=='X')cnt++;
					if(cnt==5){
						cout<<"YES"<<endl;
						return 0;
					}
				}
				rep(i,c-4,c){
					cnt=0;
					rep(j,i,i+4)if(grid[r][j]=='X')cnt++;
					if(cnt==5){
						cout<<"YES"<<endl;
						return 0;
					}
				}
				rep(i,-4,0){
					cnt=0;
					rep(j,i,i+4)if(grid[r+j][c+j]=='X')cnt++;
					if(cnt==5){
						cout<<"YES"<<endl;
						return 0;
					}
				}
				rep(i,-4,0){
					cnt=0;
					rep(j,i,i+4)if(grid[r-j][c+j]=='X')cnt++;
					if(cnt==5){
						cout<<"YES"<<endl;
						return 0;
					}
				}
				grid[r][c]='.';
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}