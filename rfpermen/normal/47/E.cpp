#include <bits/stdc++.h>
using namespace std;
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define ll long long
#define x first
#define y second
#define mp make_pair
pair<double,double> ans[10005];
pair<ll,ll> wall[100005];
double a,v,b,g,t,sud,hit,ang[10005];
ll rng[100005],n,m,le,ri,mid,c,d,aw,ak,reg[100005];
 
int main(){
	cout<<fixed<<setprecision(9);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>v;g=9.8;
	rep(i,1,n)cin>>ang[i];
	cin>>m;
	rep(i,1,m){
		cin>>a>>b;
		//if(a==1.3905)cout<<a<<" "<<b<<endl;
		a*=10000, b*=10000, wall[i].x=a+0.01, wall[i].y=b+0.01;
	}
	sort(wall+1,wall+1+m);
	//rep(i,1,n)cout<<ang[i]<<endl;
	//rep(i,1,m)cout<<wall[i].x<<" "<<wall[i].y<<endl;
	rep(i,1,m){
		le=0, ri=7853;
		a=wall[i].x, b=wall[i].y;
		a/=10000, b/=10000, c=0, d=7853;
		while(le<=ri){
			mid=(le+ri)/2;
			sud=mid; sud/=10000;
			t=a/v/cos(sud);
			hit=v*sin(sud)*t-g*t*t/2;
			if(0.00000000000000000>=hit)le=mid+1;
			else if(hit>b)ri=mid-1;
			else le=mid+1,c=mid;
			//cout<<t<<" "<<sud<<" "<<hit<<" "<<le<<" "<<ri<<endl;
		}
		//cout<<c<<endl;
		le=0, ri=7853;
		while(le<=ri){
			mid=(le+ri)/2;
			sud=mid; sud/=10000;
			t=a/v/cos(sud);
			hit=v*sin(sud)*t-g*t*t/2;
			if(0.00000000000000>hit)le=mid+1, d=mid;
			else ri=mid-1;
			//cout<<t<<" "<<sud<<" "<<hit<<" "<<le<<" "<<ri<<endl;
		}
		d++;
		//cout<<d<<endl;
		rep(j,d,c){
			if(rng[j]){
				j=reg[rng[j]];
				continue;
			}
			rng[j]=i;
			reg[i]=j;
		}
	}
	//rep(i,0,7853)cout<<i<<" "<<rng[i]<<endl;
	rep(i,1,n){
		a=ang[i];
		b=ang[i]*10;
		b*=10;
		b*=10;
		b*=10;
		c=b+0.01;
		if(rng[c]==0){
			ans[i]=(mp(v*v*sin(2*a)/g,0.0));
			//cout<<v*v*sin(2*a)/g<<" "<<0.0<<endl;
		}
		else {
			b=wall[rng[c]].x; b/=10000;
			t=b/v/cos(a);
			hit=v*sin(a)*t-g*t*t/2;
			ans[i]=(mp(b,hit));
			b=wall[rng[c]].y; b/=10000;
			//if(i==1003)cout<<ang[i]<<" "<<hit<<" "<<b<<" 0."<<wall[rng[c]].x<<endl;
			//if(hit>b)cout<<"bug "<<i<<" "<<hit<<" "<<b<<" "<<ang[i]<<" 0."<<wall[rng[c]].x<<endl;
			//cout<<b<<" "<<hit<<endl;//<<" "<<cos(a)<<" "<<sin(a)<<" "<<a
			//cout<<c<<endl;
		}
	}
	rep(i,1,n)cout<<ans[i].x<<" "<<ans[i].y<<endl;
	return 0;
}