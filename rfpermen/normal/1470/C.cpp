#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,k,nw,x,wk,res[MAX],le,ri,mid;

inline int que(int ty){
	if(ty>n)while(1);
	++wk;
	cout<<"? "<<ty<<endl;
	cin>>x;
	return x;
}
inline int aju(int z){
	z%= n;
	if(z<=0)z+= n;
	return z;
}
int f(int z){
	if(z==-1)return res[n-1];
	if(z==n)return res[0];
	return res[z];
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(n<200){
    	rep(i,1,300)que(1);
    	asd(i,0,n){
    		que(i+1);
    		res[i] = x-k;
		}
		asd(i,0,n)if(res[i]==0){
			if(f(i-1)<0 && f(i+1)>0){
				return cout<<"! "<<i+1<<endl,0;
			}
		}
		while(1);
	}
    que(1);
    nw = 1;
    rep(i,0,1000){
    	nw+= i;
    	que(nw);
    	if(x<k){
    		le = nw+1, ri = nw+wk-1;
    		while(le<=ri){
    			mid = le+ri>>1;
    			que(aju(mid));
    			if(x<k)le = mid+1;
    			else if(x>k)ri = mid-1;
    			else return cout<<"! "<<aju(mid)<<endl,0;
			}
		}
		else if(x>k){
    		le = nw-(wk-1), ri = nw-1;
    		while(le<=ri){
    			mid = (le+ri)/2;
    			que(aju(mid));
    			if(x<k)le = mid+1;
    			else if(x>k)ri = mid-1;
    			else return cout<<"! "<<aju(mid)<<endl,0;
			}
		}
	}
	return 2;
    return 0;
}