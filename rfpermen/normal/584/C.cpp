#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
//#define endl "\n"
const ll MAX = 25e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,m,a,b;
string s,t,ans;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m; m = n-m;
	cin>>s>>t;
	n--;
	rep(i,0,n){
		if(s[i]==t[i])a++;
		else b++;
	}
	b/=2;
	if(a+b<m)return cout<<-1,0;
	rep(i,0,n){
		if(s[i]==t[i]){
			if(!m){
				if(s[i]=='a')ans+='b';
				else ans+='a';
			}
			else m--, ans+=s[i];
		}
		else {
			if(st)ans+=t[i], st=0;
			else if(!m||!b){
				rep(j,'a','z')if(j!=s[i]&&j!=t[i]){
					ans+=j;
					break;
				}
			}
			else b--, m--, ans+=s[i], st=1;
		}
	}
	cout<<ans<<endl;
    return 0;
}