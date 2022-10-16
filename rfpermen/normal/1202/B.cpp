#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll ans,cnt[11][11],tms[11][11],sz,nw,x,z;
string s;
queue<int> q;
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("outrput.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    rep(i,1,sz)++cnt[s[i-1]-'0'][s[i]-'0'];
    rep(i,0,9){
    	rep(j,0,9){
	    	memset(tms,0,sizeof tms);
	    	rep(k,0,9){
	    		while(!q.empty())q.pop();
	    		q.push(k);
	    		while(!q.empty()){
	    			nw = q.front(); q.pop();
	    			x = tms[k][nw];
	    			if(!tms[k][(nw+i)%10])tms[k][(nw+i)%10] = x+1, q.push((nw+i)%10);
	    			if(!tms[k][(nw+j)%10])tms[k][(nw+j)%10] = x+1, q.push((nw+j)%10);
				}
			}
//			if(i==1&&j==0){
//				rep(k,0,9){
//					rep(o,0,9)cout<<tms[k][o]<<' ';
//					cout<<endl;
//				}
//			}
			ans = 1;
			rep(k,0,9)rep(o,0,9){
				if(ans==-1)break;
				if(!cnt[k][o])continue;
				if(!tms[k][o]){
					ans = -1; break;
				}
				ans+=cnt[k][o]*tms[k][o];
			}
			if(ans==-1)cout<<ans<<' ';
			else cout<<ans-s.size()<<' ';
		}
		cout<<endl;
	}
	return 0;
}