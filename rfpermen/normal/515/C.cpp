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

int n,x[10];
char y;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>y;
		if(y<'2')continue;
		x[y-'0']++;
	}
	rep(k,1,100){
		while(x[9]){
			x[9]--;
			x[3]+=2;
			x[2]++;
			x[7]++;
		}
		while(x[8]){
			x[2]+=3;
			x[8]--;
			x[7]++;
		}
		while(x[6]){
			x[3]++;
			x[6]--;
			x[5]++;
		}
		while(x[4]){
			x[2]+=2;
			x[4]--;
			x[3]++;
		}
	}
	rap(i,9,2)while(x[i]--)cout<<i;
    return 0;
}