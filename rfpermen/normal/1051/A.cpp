#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

ll n,x,y,z,sz,cnt,tmp,res,a,b,c,k,m;
bool v[MAX];
string s,t;
//set<int> s;

int main(){
//	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>s;
    	sz = s.size()-1;
    	a = b = c = 0;
    	for(auto i:s){
    		if(i>='0'&&i<='9')a++;
    		else if(i>='a')b++;
    		else c++;
		}
		if(!a||!b||!c){
			if(a==sz+1)s[0] = 'a', s[1] = 'A';
			else if(b==sz+1)s[0] = '1', s[1] = 'A';
			else if(c==sz+1)s[0] = '1', s[1] = 'a';
			else if(!a){
				if(b>1){
					rep(i,0,sz){
						if(s[i]>='a'){
							s[i] = '1';
							break;
						}
					}
				}
				else {
					rep(i,0,sz){
						if(s[i]<='Z'){
							s[i] = '1';
							break;
						}
					}
				}
			}
			else if(!b){
				if(c>1){
					rep(i,0,sz){
						if(s[i]>='A'){
							s[i] = 'a';
							break;
						}
					}
				}
				else {
					rep(i,0,sz){
						if(s[i]<='9'){
							s[i] = 'a';
							break;
						}
					}
				}
			}
			else if(!c){
				if(b>1){
					rep(i,0,sz){
						if(s[i]>='a'){
							s[i] = 'A';
							break;
						}
					}
				}
				else {
					rep(i,0,sz){
						if(s[i]<='9'){
							s[i] = 'A';
							break;
						}
					}
				}
			}
		}
		cout<<s<<endl;
	}
    return 0;
}