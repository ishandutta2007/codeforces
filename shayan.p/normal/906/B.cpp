// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=2e5+10;

deque<ll>dn,dm;
void Do(ll num,deque<ll>&d){
	if(num==1){
		d.PB(1);
		return;
	}
	if(num==2){
		d.PB(1);
		d.PB(2);
		return;
	}
	if(num==3){
		d.PB(2);
		d.PB(1);
		d.PB(3);
		return;
	}
	d.PB(2);
	d.PB(4);
	d.PB(1);
	d.PB(3);
	FOR(i,5,num){
		if(i%2){
			d.PB(i);
		}
		else{
			d.PF(i);
		}
	}
}
int main(){
	ll n,m;cin>>n>>m;
	Do(n,dn);
	Do(m,dm);
	if(n>3&&m>3){
		cout<<"YES\n";
		REP(i,n){
			REP(j,m){
				cout<<(dn[i]-1)*m+dm[j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(n==3){
		if(m<3){
			cout<<"NO";
		}
		else if(m==3){
			cout<<"YES\n6 1 8\n7 5 3\n2 9 4";
		}
		else if(m==4){
			cout<<"YES\n5 4 7 2\n3 6 1 8\n10 12 9 11";
		}
		else{
			cout<<"YES\n";
			REP(i,m)cout<<dm[i]<<" ";cout<<endl;
			REP(i,m)cout<<m+(dm[i]==m?1:dm[i]+1)<<" ";cout<<endl;
			REP(i,m)cout<<2*m+dm[i]<<" ";
		}
	}
	else if(n==2){
		if(m<4){
			cout<<"NO";
		}
		else if(m==4){
			cout<<"YES\n5 4 7 2\n3 6 1 8";
		}
		else{
			cout<<"YES\n";
			REP(i,m)cout<<dm[i]<<" ";cout<<endl;
			REP(i,m)cout<<m+(dm[i]==m?1:dm[i]+1)<<" ";
		}
	}
	else if(n==1){
		if(m==1){
			cout<<"YES\n1";
		}
		else if(m<4){
			cout<<"NO";
		}
		else{
			cout<<"YES\n";
			REP(i,m){
				cout<<dm[i]<<" ";
			}
		}
	}
	else if(m==3){// n>3
		if(n==4){
			cout<<"YES\n6 7 2\n12 5 10\n3 1 8\n9 11 4";
		}
		else{
			cout<<"YES\n";
			REP(i,n){
				cout<<m*(dn[i]-1)+1<<" "<<m*((dn[i]==n?1:dn[i]+1)-1)+2<<" "<<m*(dn[i]-1)+3<<endl;
			}
		}
	}
	else if(m==2){
		if(n==4){
			cout<<"YES\n2 5\n7 4\n6 1\n3 8";
		}
		else{
			cout<<"YES\n";
			REP(i,n){
				cout<<m*(dn[i]-1)+1<<" "<<m*((dn[i]==n?1:dn[i]+1)-1)+2<<endl;
			}
		}
	}
	else if(m==1){
		cout<<"YES\n";
		REP(i,n){
			cout<<dn[i]<<endl;
		}
	}
}