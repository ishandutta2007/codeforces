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
const int MAX = 5e5+10;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int tc,n,z,ls,x[MAX],cnt[MAX],id,a,b,c,le,ri,mid,res,ax,bx,cx;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	ls = -1;
    	id = a = b = c = 0;
    	rep(i,1,n){
    		cin>>z;
    		if(ls!=z)++id, cnt[id] = 0, ls = z;
    		cnt[id]++;
		}
		z = n;
		rep(i,1,id){
			cnt[i]+= cnt[i-1];
			if(cnt[i]+cnt[i]>z){
				id = i-1;
				break;
			}
		}
		n = id;
		rep(i,1,n){
			le = i+1, ri = n;
			ax = cnt[i];
			while(le<=ri){
				mid = le+ri>>1;
				bx = cnt[mid] - cnt[i];
				cx = cnt[n] - cnt[mid];
				if(bx<=ax)le = mid+1;
				else if(cx<=ax)ri = mid-1;
				else {
					a = ax, b = bx, c = cx;
					break;
				}
			}
			if(a)break;
		}
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
    return 0;
}