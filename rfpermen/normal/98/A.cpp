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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int ans;
string s,t;
set<string> st;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sort(all(s));
    do {
    	t = s;
    	if(!st.count(t)){
    		++ans;
//    		cout<<t<<endl;
    		rep(i,1,4){
    			st.insert(t);
    			rep(j,1,3)swap(t[j],t[j+1]);
			}
			reverse(t.begin()+1,t.begin()+5);
			swap(t[0],t[5]);
    		rep(i,1,4){
    			st.insert(t);
    			rep(j,1,3)swap(t[j],t[j+1]);
			}
			swap(t[0],t[5]);
			reverse(t.begin()+1,t.begin()+5);
			
			swap(t[0],t[1]), swap(t[5],t[3]);
			reverse(t.begin()+1,t.begin()+5);
    		rep(i,1,4){
    			st.insert(t);
    			rep(j,1,3)swap(t[j],t[j+1]);
			}
			reverse(t.begin()+1,t.begin()+5);
			swap(t[0],t[5]);
    		rep(i,1,4){
    			st.insert(t);
    			rep(j,1,3)swap(t[j],t[j+1]);
			}
			swap(t[0],t[5]);
			reverse(t.begin()+1,t.begin()+5);
			reverse(t.begin()+1,t.begin()+5);
			swap(t[0],t[1]), swap(t[5],t[3]);
			
			swap(t[0],t[2]), swap(t[5],t[4]);
			reverse(t.begin()+1,t.begin()+5);
    		rep(i,1,4){
    			st.insert(t);
    			rep(j,1,3)swap(t[j],t[j+1]);
			}
			swap(t[0],t[5]);
			reverse(t.begin()+1,t.begin()+5);
    		rep(i,1,4){
    			st.insert(t);
    			rep(j,1,3)swap(t[j],t[j+1]);
			}
		}
	}while(next_permutation(all(s)));
	cout<<ans<<endl;
	return 0;
}