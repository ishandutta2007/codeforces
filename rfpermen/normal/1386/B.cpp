#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
ll q,n,x[3][MAX],a,b,o,z,cnt,sm,pos,cs,cs2,swp;
char ty;
map<pll,int> jlh;
map<int,int> sud;
multiset<int> ag;
 
inline void simp(int k){
	z = x[0][k];
	rep(i,1,2)z = __gcd(z,x[i][k]);
	rep(i,0,2)x[i][k]/= z;
	return;
}
 
inline void get(int n){
	a = x[1][n]*x[0][0] - x[1][0]*x[0][n], b = x[2][n]*x[0][0] - x[2][0]*x[0][n];
	return;
}
 
inline void ins(int a,int b){
	int c = a-b;
	if(c<0)c+= cs2;
	ag.insert(c);
	return;
}
 
inline void rem(int a,int b){
	int c = a-b;
	if(c<0)c+= cs2;
	ag.erase(ag.find(c));
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cs = round(pi*10000000.0), cs2 = round(pi*20000000.0);
    ag.insert(cs2);
    rep(i,0,2)cin>>x[i][0]; simp(0);
    if(x[0][0]==0){
    	rep(i,1,2)if(x[i][0]){
    		swp = i;
    		swap(x[0][0],x[i][0]);
    		break;
		}
	}
    cin>>q;
    auto it = sud.begin(), it2 = sud.begin();
    while(q--){
    	cin>>ty;
    	if(ty=='A'){
    		++n;
    		rep(i,0,2)cin>>x[i][n]; simp(n);
    		if(swp)swap(x[0][n],x[swp][n]); get(n);
    		bool st = 1;
    		rep(i,0,2)if(x[i][0]!=x[i][n])st = 0;
    		
    		if(st)++cnt;
    		else {
    			z = abs(__gcd(a,b));
				a/=z, b/=z;
				jlh[{a,b}]++;
				if(jlh.count({-a,-b}))sm+= jlh[{-a,-b}];
				
				pos = round(atan2(b,a)*10000000.0);
				if(pos<0)pos+= cs2;
				
				if(sud.count(pos))sud[pos]++;
				else {
					if(sud.empty())sud[pos]++;
					else if(sud.size()==1){
						ag.erase(cs2);
						sud[pos]++;
						it = sud.find(pos);
						if(it==sud.begin())++it;
						else --it;
						ins(pos,(*it).fi);
						ins((*it).fi,pos);
					}
					else {
						sud[pos]++;
						it2 = it = sud.find(pos);
						if(it==sud.begin())it = sud.end();
						--it;
						++it2;
						if(it2==sud.end())it2 = sud.begin();
						rem((*it2).fi,(*it).fi);
						ins((*it2).fi,pos);
						ins(pos,(*it).fi);
					}
				}
			}
		}
		else {
			cin>>o;
			get(o);
			if(a==0 && b==0)--cnt;
    		else {
    			z = abs(__gcd(a,b));
				a/=z, b/=z;
				if(jlh[{a,b}]==1)jlh.erase({a,b});
				else jlh[{a,b}]--;
				if(jlh.count({-a,-b}))sm-= jlh[{-a,-b}];
				
				pos = round(atan2(b,a)*10000000.0);
				if(pos<0)pos+= cs2;
				
				if(sud[pos]>1)sud[pos]--;
				else {
					if(sud.size()==1)sud.clear();
					else if(sud.size()==2){
						ag.clear();
						ag.insert(cs2);
						sud.erase(pos);
					}
					else {
						it2 = it = sud.find(pos);
						if(it==sud.begin())it = sud.end();
						--it;
						++it2;
						if(it2==sud.end())it2 = sud.begin();
						rem((*it2).fi,pos);
						rem(pos,(*it).fi);
						ins((*it2).fi,(*it).fi);
						sud.erase(pos);
					}
				}
			}
		}
		if(cnt)cout<<"1\n";
		else if(sm)cout<<"2\n";
		else if((*ag.rbegin())<=cs)cout<<"3\n";
		else cout<<"0\n";
	}
	return 0;
}