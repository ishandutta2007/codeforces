#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,a,b,c,x,y;
char ans[105][105];
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>a>>b>>c;
    if((n&1)&&(m&1))return cout<<"IMPOSSIBLE\n",0;
    if(n&1){
    	if(a*2<m)return cout<<"IMPOSSIBLE\n",0;
    	a-=m/2;
    	rep(i,1,m/2)ans[1][i*2-1] = ans[1][i*2] = 'x' + (i&1);
		x = 1;
    	if(a/2+b/2+c<(n-1)*m/4)return cout<<"IMPOSSIBLE\n",0;
	}
	else if(m&1){
    	if(b*2<n)return cout<<"IMPOSSIBLE\n",0;
    	b-=n/2;
    	rep(i,1,n/2)ans[i*2-1][1] = ans[i*2][1] = 'x' + (i&1);
		y = 1;
    	if(a/2+b/2+c<(m-1)*n/4)return cout<<"IMPOSSIBLE\n",0;
	}
	else if(a/2+b/2+c<m*n/4)return cout<<"IMPOSSIBLE\n",0;
	rep(i,1,n/2){
		rep(j,1,m/2){
			if(a>=2){
				ans[i*2-1+x][j*2-1+y] = ans[i*2-1+x][j*2+y] = 'a' + 2*(i&1) + (j&1);
				ans[i*2+x][j*2-1+y] = ans[i*2+x][j*2+y] = 'e' + 2*(i&1) + (j&1);
				a-=2;
			}
			else if(b>=2){
				ans[i*2-1+x][j*2-1+y] = ans[i*2+x][j*2-1+y] = 'i' + 2*(i&1) + (j&1);
				ans[i*2-1+x][j*2+y] = ans[i*2+x][j*2+y] = 'm' + 2*(i&1) + (j&1);
				b-=2;
			}
			else ans[i*2-1+x][j*2-1+y] = ans[i*2+x][j*2-1+y] = ans[i*2-1+x][j*2+y] = ans[i*2+x][j*2+y] = 'q' + 2*(i&1) + (j&1);
		}
	}
	rep(i,1,n){
		rep(j,1,m)cout<<ans[i][j];
		cout<<endl;
	}
    return 0;
}