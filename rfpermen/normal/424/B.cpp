#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
ll gcd(ll r,ll v){
	if(v==0)return r;
	return gcd(v,r%v);
}
ll a,n,k,mid,le,ri;
pair<double,int> cit[1005];
double x,y,rad;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(7);
	cin>>a>>k;
	k=1e6-k;
	rep(i,1,a){
		cin>>x>>y>>cit[i].se;
		cit[i].fi=sqrt(x*x + y*y);
	}
	sort(cit+1,cit+1+a);
	rep(i,2,a)cit[i].se+=cit[i-1].se;
	le=1, ri=a;
	while(le<=ri){
		mid=(le+ri)/2;
		if(cit[mid].se<k)le=mid+1;
		else {
			ri=mid-1;
			rad=cit[mid].fi;
		}
	}
	if(rad==0)cout<<-1<<endl;
	else cout<<rad<<endl;
	return 0;
}