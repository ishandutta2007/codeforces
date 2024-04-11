#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,k,id,p[1005],cek;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
	k = sqrt(n);
	st=1;
	rep(i,2,k)if(n%i==0)st=0;
	if(st)return cout<<"1\n"<<n,0;
	rep(i,2,100000){
		if(id==1000)break;
		k = sqrt(i);
		st=1;
		rep(j,2,k)if(i%j==0)st=0;
		if(st)p[++id]=i;
	}
	n-=3;
	rep(i,1,1000){
		cek = n-p[i];
		k = sqrt(cek);
		st=1;
		rep(j,2,k)if(cek%j==0)st=0;
		if(st)return cout<<"3\n3 "<<p[i]<<" "<<cek,0;
	}
    return 0;
}