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
const int MAX=1005;
int n,k,x[MAX],ans;
int main(){
	cin>>n>>k;
	rep(i,1,n)cin>>x[i];
	sort(x+1,x+1+n);
	rep(i,1,n){
		while(2*k<x[i]){
			k*=2;
			ans++;
		}
		if(k<x[i])k=x[i];
	}
	cout<<ans<<endl;
	return 0;
}