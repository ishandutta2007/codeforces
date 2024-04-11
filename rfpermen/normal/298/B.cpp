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
ll n,sx,sy,ex,ey;
char win[100005];
int main(){
	cin>>n>>sx>>sy>>ex>>ey;
	rep(i,1,n)cin>>win[i];
	rep(i,1,n){
		if(win[i]=='N'){
			if(sy<ey)sy++;
		}
		if(win[i]=='E'){
			if(sx<ex)sx++;
		}
		if(win[i]=='W'){
			if(sx>ex)sx--;
		}
		if(win[i]=='S'){
			if(sy>ey)sy--;
		}
		if(sx==ex && sy==ey){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}