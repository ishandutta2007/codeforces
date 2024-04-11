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
int n,x,dis[100005],prime[100005],cnt,idx;
bool prima[100001],stat;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int X=100001;
	memset(prima,true,sizeof prima);
	prima[0]=false; prima[1]=false;
	for( int i=2;i*i<= X;i++){
		if (prima[i]) {
			for( int j=i*i; j<=X; j += i) {
				prima[j]= false;
			}
		}
	}
	rep(i,1,100001){
		if(prima[i])cnt++, prime[cnt]=i;
	}
	cin>>n;
	rep(i,1,n){
		cin>>x;
		if(prima[x])dis[x]--, x=1;
		idx=1, stat=1;
		while(x>1){
			if(x%prime[idx]==0){
				x/=prime[idx];
				if(stat)dis[prime[idx]]--;
				stat=0;
			}else idx++, stat=1;
		}
		
	}
	sort(dis+1,dis+100001);
	cout<<max(1,-dis[1])<<endl;
}