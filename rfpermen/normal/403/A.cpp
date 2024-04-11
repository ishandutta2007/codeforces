#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i = n; i<=N; i++)
#define rap(i,n,N) for(int i = n; i>=N; i--)
const ll MOD = 1000000007;
const int dr[] = {0,0,0,1,-1};
const int dc[] = {0,1,-1,0,0};


int tc,n,p,x;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	while(tc--){
		cin>>n>>p;
		x = 2*n+p;
		rep(i,1,n)rep(j,i+1,n){
			if(!x)break;
			cout<<i<<' '<<j<<endl;
			--x;
		}
	}
	return 0;
}