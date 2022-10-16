#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll tc,n,x[MAX],cnt,cl;
bool st;
 
int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)cin>>x[i];
    	cnt = 0;
    	rep(i,2,n)if(x[i-1]!=x[i])++cnt;
    	if(x[1]!=x[n])++cnt;
    	if(!cnt){
    		cout<<"1\n";
    		rep(i,1,n)cout<<"1 ";
    		cout<<endl;
		}
		else if(n%2==0){
    		cout<<"2\n";
    		rep(i,1,n>>1)cout<<"1 2 ";
    		cout<<endl;
		}
		else if(cnt==n){
			cout<<"3\n";
    		rep(i,1,n/3)cout<<"1 2 3 ";
    		if(n%3==1)cout<<2;
    		else if(n%3==2)cout<<"1 2";
    		cout<<endl;
		}
		else {
			cout<<"2\n1";
			cl = st = 0;
			rep(i,2,n){
				if(st||x[i]!=x[i-1])cl^=1;
				else st = 1;
				cout<<' '<<cl+1;
			}
			cout<<endl;
		}
	}
	return 0;
}