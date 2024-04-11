#include <bits/stdc++.h>

#pragma GCC optimize("Os")
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,q,l,r,x[3][MAX],a[3],jlh;
string s;
bool st;

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s; n = s.size();
    rep(i,1,n){
    	rep(j,0,2)x[j][i] = x[j][i-1];
    	x[s[i-1]-'x'][i]++;
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		if(r-l<2){
			cout<<"YES\n"; continue;
		}
		rep(i,0,2)a[i] = x[i][r] - x[i][l-1];
		sort(a,a+3);
		r = (r-l+1);
		l = r%3, r/=3;
//		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<l<<endl;
		rap(i,2,2-l+1)a[i]--;
		if(a[0]!=a[1]||a[1]!=a[2])cout<<"NO\n";
		else cout<<"YES\n";
	}
    
    return 0;
}