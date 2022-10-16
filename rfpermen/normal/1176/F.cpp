#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,k,c,x,id;
ll dp[MAX][10],z[MAX][7],cnt[MAX][4];
priority_queue<int> pq[4];

ll f(int nw,int st){
	if(nw>n)return 0;
	if(dp[nw][st]!=-1)return dp[nw][st];
	ll ret = f(nw+1,st), tmp;
	tmp = max(z[nw][1],max(z[nw][4],z[nw][6]));
	ret = max(ret,f(nw+1,(st+1)%10) + tmp + (st==9 ? tmp : 0));
	if(cnt[nw][1]>=2){
		ret = max(ret,f(nw+1,(st+2)%10) + z[nw][1]+z[nw][2] + (st>=8 ? z[nw][1] : 0));
	}
	if(cnt[nw][1]&&cnt[nw][2]){
		ret = max(ret,f(nw+1,(st+2)%10) + z[nw][1]+z[nw][4] + (st>=8 ? max(z[nw][4],z[nw][1]) : 0));
	}
	if(cnt[nw][1]==3){
		ret = max(ret,f(nw+1,(st+3)%10) + z[nw][1]+z[nw][2]+z[nw][3] + (st>=7 ? z[nw][1] : 0));
	}
	return dp[nw][st] = ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>k;
    	rep(j,1,3)while(!pq[j].empty())pq[j].pop();
    	rep(j,1,k){
    		cin>>c>>x;
    		pq[c].push(x);
		}
		id = 0;
		rep(j,1,3){
			if(pq[1].empty())break;
			z[i][++id] = pq[1].top();
			cnt[i][1]++;
			pq[1].pop();
		}
		id = 3;
		rep(j,1,2){
			if(pq[2].empty())break;
			z[i][++id] = pq[2].top();
			cnt[i][2]++;
			pq[2].pop();
		}
		id = 5;
		rep(j,1,1){
			if(pq[3].empty())break;
			z[i][++id] = pq[3].top();
			cnt[i][3]++;
			pq[3].pop();
		}
	}
	memset(dp,-1,sizeof dp);
	cout<<f(1,0)<<endl;
	return 0;
}