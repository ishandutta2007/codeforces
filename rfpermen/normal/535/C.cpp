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

ll q,a,b,l,le,ri,mid,cek,t,m,res,ttl,a1,an;

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>q;
    while(q--){
    	cin>>l>>t>>m;
    	le = l, ri = l+1e9, res = -1, a1 = a + (l-1)*b;
    	while(le<=ri){
    		mid = (le+ri)/2;
    		an = a + (mid-1)*b;
    		ttl = (mid-l+1)*(a1+an)/2;
//    		cout<<le<<" "<<ri<<" "<<mid<<" "<<m*t<<" >= "<<ttl<<" >>> an = "<<an<<endl;
    		cek = max(an,(ttl+m-1)/m);
    		if(cek>t)ri = mid-1;
    		else res = mid, le = mid+1;
		}
		cout<<res<<endl;
	}
    return 0;
}