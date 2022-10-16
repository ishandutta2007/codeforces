#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,x,y,z;
string s;
bool cek(string t){
	if(t[0]!='R'||t[1]>'9'||t.size()<3)return 0;
	for(int i = 2; i<t.size(); ++i)if(t[i]=='C')return 1;
	return 0;
}


int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>s;
    	if(!cek(s)){
    		x = y = 0;
    		for(auto i:s){
    			if(i>'9')y = y*26+i-'A'+1;
    			else x = x*10+i-'0';
			}
			cout<<'R'<<x<<'C'<<y<<endl;
		}
		else {
			x = y = z = 0;
    		for(auto i:s){
    			if(i>'9')z++;
    			else if(z==2)x = x*10+i-'0';
    			else y = y*10+i-'0';
			}
			s = "";
			while(x){
				s.pb(x%26+'A'-1), x/=26;
				if(s.back()=='@')s.back()='Z', x--;
			}
			reverse(s.begin(),s.end());
			cout<<s<<y<<endl;
		}
	}
    return 0;
}