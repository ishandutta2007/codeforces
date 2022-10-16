#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int tc,n,lps[MAX],mx,sz,opt;
string s,ans;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>s;
    	mx = 0, sz = s.size()<<1;
    	rep(i,0,sz)lps[i] = 0;
    	lps[0] = 0; lps[1] = 1;
		rep(i,2,sz){
		    int l = i/2 - lps[i]/2;
		    int r = (i-1)/2 + lps[i]/2;
		    while(1){ // widen
		        if(l == 0 || r+1 == s.size())break;
		        if(s[l-1] != s[r+1])break;
		        l--, r++;
		    }
		    lps[i] = r - l + 1;
		    // jump
		    if(lps[i] > 2){
		        int j = i-1, k = i+1; // while lps[j] inside lps[i]
		        while(lps[j] - j < lps[i] - i) lps[k++] = lps[j--];
		        lps[k] = lps[i] - (i - j); // set lps[k] to edge of lps[i]
		        i = k-1; // jump to mirror, which is k
		    }
		}
//		rep(i,1,sz)cout<<lps[i]<<' '; cout<<endl;
		rep(i,1,sz){
			if(i==lps[i]||i+lps[i]==sz)mx = max(mx,lps[i]);
		}
		
		if(mx==s.size()){
			cout<<s<<endl;
			continue;
		}
		
		n = s.size()-1;
		
		rep(i,0,n/2){
			if(s[i]!=s[n-i]){
				opt = 0;
				for(int j = i; j<=n/2; ++j){
					if(j-lps[j*2+1]/2<=i)opt = max(opt,(j-i)*2+1);
					if(j-lps[j*2]/2<=i)opt = max(opt,(j-i)*2);
				}
				for(int j = n-i; j>n/2; --j){
					if(j+lps[j*2+1]/2>=n-i)opt = max(opt,((n-i)-j)*2+1);
					if(j+lps[j*2]/2>n-i)opt = max(opt,((n-i)-j)*2+2);
				}
//				db(opt);
				ans = "";
				if(opt+i*2>mx){
					rep(j,0,i-1)ans.pb(s[j]);
					
					st = 0;
					for(int j = i; j<=n/2; ++j){
						if(st)break;
						if(j-lps[j*2+1]/2<=i && (j-i)*2+1 == opt){
							opt+= i-1;
							rep(k,i,opt)ans.pb(s[k]);
							st = 1;
						}
						if(j-lps[j*2]/2<=i && (j-i)*2 == opt){
							opt+= i-1;
							rep(k,i,opt)ans.pb(s[k]);
							st = 1;
						}
					}
					
					for(int j = n-i; j>=n/2; --j){
						if(st)break;
						if(j+lps[j*2+1]/2>=n-i && ((n-i)-j)*2+1 == opt){
							opt = n-i-opt+1;
							rep(k,opt,n-i)ans.pb(s[k]);
							st = 1;
						}
						if(j+lps[j*2]/2>n-i && ((n-i)-j)*2+2 == opt){
							opt = n-i-opt+1;
							rep(k,opt,n-i)ans.pb(s[k]);
							st = 1;
						}
					}
					
					rep(j,n-i+1,n)ans.pb(s[j]);
				}
				else {
					rep(j,1,sz){
						if((j==lps[j]||j+lps[j]==sz) && lps[j]==mx){
							--mx;
							if(j==lps[j]){
								rep(k,0,mx)ans.pb(s[k]);
							}
							else {
								rep(k,n-mx,n)ans.pb(s[k]);
							}
							break;
						}
					}
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}