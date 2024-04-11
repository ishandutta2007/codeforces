#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=200005;
const int MOD=1000000000 + 7;
int n;
double m1,x[10000],p2;
int main(){
	//cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i];
	rep(j,2,n){
		p2=-1;
		m1=(x[j]-x[1])/(j-1);
		//cout<<m1<<endl;
		rep(i,2,n){
			if(m1!=(x[i]-x[1])/(i-1)){
				p2=i;
				break;
			}
		}
		if(p2==-1){
			cout<<"No"<<endl;
			return 0;
		}
		rep(i,2,n){
			if(m1!=(x[i]-x[1])/(i-1)){
				if(i==p2){
					if(i==n){
				cout<<"YES"<<endl;
				return 0;
			}
					continue;
				}
				if(m1!=(x[i]-x[(int)p2])/(i-p2))break;
			}
			if(i==n){
				//cout<<p2<<" "<<cnt<<" "<<m1<<" "<<j<<endl;
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	m1=(x[3]-x[2]);
	rep(i,3,n){
		if(m1!=(x[i]-x[2])/(i-2))break;
		else if(n==i){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}