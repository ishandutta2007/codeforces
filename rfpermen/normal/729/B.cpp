#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define MAX 10005
using namespace std;
ll n,m,stat,now;
int x[1005][1005];
int main(){
	cin>>n>>m;
	rep(i,1,n){
		rep(j,1,m)scanf("%d",&x[i][j]);
	}
	rep(i,1,n){
		stat=0;
		rep(j,1,m){
			if(x[i][j]==1){
				stat=1;
				continue;
			}
			if(stat)now++;
		}
	}
	rep(i,1,n){
		stat=0;
		rap(j,m,1){
			if(x[i][j]==1){
				stat=1;
				continue;
			}
			if(stat)now++;
		}
	}
	rep(j,1,m){
		stat=0;
		rep(i,1,n){
			if(x[i][j]==1){
				stat=1;
				continue;
			}
			if(stat)now++;
		}
	}
	rep(j,1,m){
		stat=0;
		rap(i,n,1){
			if(x[i][j]==1){
				stat=1;
				continue;
			}
			if(stat)now++;
		}
	}
	cout<<now<<endl;
	return 0;
}