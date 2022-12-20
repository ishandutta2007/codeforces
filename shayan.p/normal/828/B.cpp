// Believe in yourself...
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll b,u,d,r,l;
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=n;i>0;i--){
		string s;cin>>s;
		for(ll j=1;j<=m;j++){
			if(s[j-1]=='B'){
				b++;
				if(u==0)u=i;
				if(d==0)d=i;
				if(r==0)r=j;
				if(l==0)l=j;
				u=max(u,i);
				d=min(d,i);
				l=min(l,j);
				r=max(r,j);
			}
		}
	}
	ll Leng=max(u-d+1,r-l+1);
	if((Leng==u-d+1&&Leng>m)||(Leng==r-l+1&&Leng>n)){
		cout<<-1;
		return 0;
	}
	cout<<(Leng*Leng)-b;
}