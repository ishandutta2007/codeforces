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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
//#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1100000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
 
int tc,n,m,k,a,b,cnt[MAX];
vector<int> v[MAX],tmp;
unordered_set<int> u[MAX];
set<pii> s;
 
inline bool make(int x){
	s.clear();
	rep(i,1,n){
		u[i].clear();
		for(int j:v[i])u[i].insert(j);
		cnt[i] = v[i].size();
		s.insert({v[i].size(),i});
	}
	while(s.size()>x && (*s.begin()).fi<x){
		a = (*s.begin()).se;
		s.erase(*s.begin());
		for(int i:u[a]){
			s.erase({cnt[i],i});
			u[i].erase(a);
			--cnt[i];
			s.insert({cnt[i],i});
		}
	}
	if(s.size()==x)return false;
	return true;
}
 
int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>m>>k;
    	rep(i,1,n)v[i].clear();
    	rep(i,1,m){
    		cin>>a>>b;
    		v[a].pb(b);
    		v[b].pb(a);
		}
//		db((ll)k*(k-1)/2);
		if((ll)k*(k-1)/2>m){cout<<"-1\n"; continue;}
		if(k==1){cout<<"2\n1\n"; continue;}
		if(k==2){
			if(n==1)return 1;
			rep(i,1,n)if(!v[i].empty()){
				cout<<"2\n"<<i<<' '<<v[i][0]<<endl;
				break;
			}
			continue;
		}
		if(make(k)){
			cout<<"1 "<<s.size()<<endl;
			for(pii i:s)cout<<i.se<<' ';
			cout<<endl;
		}
		else if(make(k-1)){
			bool st = 0;
			while(s.size()>=k){
				if((*s.begin()).fi>k-1)return 1;
				a = (*s.begin()).se, b = (*s.begin()).fi;
				s.erase(*s.begin());
				if(b==k-1){
					tmp.clear();
					for(int i:u[a])tmp.pb(i);
					random_shuffle(all(tmp));
					int sz = tmp.size()-1;
					st = 1;
					rep(i,0,sz)rep(j,i+1,sz){
						if(!st)break;
						if(!u[tmp[i]].count(tmp[j]))st = 0;
					}
					if(st){
						cout<<"2\n";
						cout<<a<<' ';
						for(int i:tmp)cout<<i<<' ';
						cout<<endl;
						break;
					}
				}
				for(int i:u[a]){
					s.erase({cnt[i],i});
					u[i].erase(a);
					--cnt[i];
					s.insert({cnt[i],i});
				}
			}
			if(!st)cout<<"-1\n";
		}
		else cout<<"-1\n"<<endl;
	}
	return 0;
}