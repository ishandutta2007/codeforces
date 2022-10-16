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
#define fi first
#define se second
const int MAX=1005;
int n,a,b,mx,x,y,tmp;
pair<int,int> seal[105];
int main(){
	//cout<<fixed<<setprecision(9);
	//ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>a>>b;
	rep(i,1,n)cin>>seal[i].fi>>seal[i].se;
	rep(i,1,n-1){
		rep(j,i+1,n){
			tmp=seal[i].fi*seal[i].se+seal[j].fi*seal[j].se;
			x=seal[i].fi+seal[j].fi; y=max(seal[i].se,seal[j].se);
			if((x<=a && y<=b) || (x<=b && y<=a)){
				if(tmp>mx)mx=tmp;
			}
			x=seal[i].fi+seal[j].se; y=max(seal[i].se,seal[j].fi);
			if((x<=a && y<=b) || (x<=b && y<=a)){
				if(tmp>mx)mx=tmp;
			}
			x=seal[i].se+seal[j].fi; y=max(seal[i].fi,seal[j].se);
			if((x<=a && y<=b) || (x<=b && y<=a)){
				if(tmp>mx)mx=tmp;
			}
			x=seal[i].se+seal[j].se; y=max(seal[i].fi,seal[j].fi);
			if((x<=a && y<=b) || (x<=b && y<=a)){
				if(tmp>mx)mx=tmp;
			}
		}
	}
	cout<<mx<<endl;
	return 0;
}