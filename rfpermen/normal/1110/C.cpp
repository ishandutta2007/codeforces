#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=998244353;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,x,y,z,a;
map<int,int> m;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    m[33554431] = 1082401;
m[16777215] = 5592405;
m[8388607] = 178481;
m[4194303] = 1398101;
m[2097151] = 299593;
m[1048575] = 349525;
m[524287] = 1;
m[262143] = 87381;
m[131071] = 1;
m[65535] = 21845;
m[32767] = 4681;
m[16383] = 5461;
m[8191] = 1;
m[4095] = 1365;
    cin>>n;
    while(n--){
    	cin>>x;
    	z = x, y = 0, a = 1;
    	while(z)y|=((z&1)==0)*a, a<<=1, z>>=1;
    	if(y==0){
    		if(m[x]==0){
    			int ans = 1, aa = x-1;
				rep(i,1,aa){
					if(ans<__gcd(x^i,x&i))ans = __gcd(x^i,x&i);
				}
				m[x] = ans;
			}
			cout<<m[x]<<endl;
//    		cout<<"m["<<x<<"] = "<<m[x]<<";\n";
		}
    	else cout<<__gcd(x^y,x&y)<<endl;
	}
    return 0;
}