#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,m,a,b,c,d,x,y,A,B,z;
string s,t;

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n; m = n/2;
	cin>>s>>t; s = '0'+s, t = '0'+t;
	rep(i,1,n){
		if(s[i]=='1'){
			if(t[i]=='0')++a;
			else ++c;
		}
		else if(t[i]=='1')++b;
	}
	rep(i,0,a)rep(j,0,b){
		A = i+j, B = a+b-i-j;
		x = i, y = b-j;
		z = abs(x-y);
		if(((x+y+c)&1) || z>c)continue;
		if(x<y)A+= z;
		else B+= z;
		A+= c-z>>1, B+= c-z>>1;
		if(A>m || B>m)continue;
		a = i, b = j, c = A-i-j, d = m-A;
		rep(i,1,n){
			if(s[i]=='1'){
				if(t[i]=='0'){
					if(a)cout<<i<<' ', a--;
				}
				else if(c)cout<<i<<' ', c--;
			}
			else {
				if(t[i]=='1'){
					if(b)cout<<i<<' ', b--;
				}
				else if(d)cout<<i<<' ', d--;
			}
		}
		cout<<endl;
		return 0;
	}
	cout<<"-1\n";
	return 0;
}