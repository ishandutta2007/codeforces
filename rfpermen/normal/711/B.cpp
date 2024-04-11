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
const int MAX=5e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

ll n,x[MAX][MAX],y[MAX],z[MAX],a,b,cek,dga,dgb;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1)return cout<<1,0;
    rep(i,1,n)rep(j,1,n){
    	cin>>x[i][j];
		y[i]+=x[i][j], z[j]+=x[i][j];
		if(i==j)dga+=x[i][j];
		if(j==n-i+1)dgb+=x[i][j];
    	if(!x[i][j])a = i, b = j;
	}
	if(y[a]!=z[b])return cout<<-1,0;
	if(a==b&&y[a]!=dga)return cout<<-1,0;
	if(n-a+1==b&&y[a]!=dgb)return cout<<-1,0;
	if(a!=1)cek = y[1];
	else cek = y[2];
	if(a!=b&&cek!=dga)return cout<<-1,0;
	if(b!=n-a+1&&cek!=dgb)return cout<<-1,0;
	rep(i,1,n){
		if(i!=a&&cek!=y[i])return cout<<-1,0;
		if(i!=b&&cek!=z[i])return cout<<-1,0;
	}
	if(y[a]>=cek)return cout<<-1,0;
	cout<<cek-y[a];
    return 0;
}