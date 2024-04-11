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

ll tc,a,b,c,d,x[3];
bool ans;

inline bool cek(){
	sort(x,x+3);
//	cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
//	cout<<2*x[2]-x[0]-x[1]<<" "<<a<<endl;
	if(x[0]<0||2*x[2]-x[0]-x[1]>a||(a-2*x[2]+x[0]+x[1])%3||x[0]+x[1]+x[2]>b||(x[0]+x[1]+x[2])%3!=b%3)return  0;
	return 1;
}

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>a>>b>>c>>d;
    	if(c>d)c^=d^=c^=d;
    	a-=b;
    	ans = 0;
    	x[0] = 0, x[1] = c, x[2] = d;
    	ans|=cek();
    	x[0] = 0, x[1] = c, x[2] = c+d;
    	ans|=cek();
    	x[0] = 0, x[1] = d, x[2] = c+d;
    	ans|=cek();
    	x[0] = 0, x[1] = c-d, x[2] = c;
    	ans|=cek();
    	x[0] = 0, x[1] = d-c, x[2] = d;
    	ans|=cek();
    	if(ans)cout<<"yes\n";
    	else cout<<"no\n";
	}
    return 0;
}