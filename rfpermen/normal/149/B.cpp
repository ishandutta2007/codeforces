#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll sz,ans,id[65],tmp,pos,rel[128],dg;
string s,a,b;
char c;
bool st;
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,9){
    	c = '0'+i;
    	rel[c] = i;
	}
	rep(i,0,25){
		c = 'A'+i;
		rel[c] = i+10;
	}
    cin>>s;
    sz = s.size()-1;
    rep(i,0,sz){
    	if(s[i]==':'){
    		pos = i+1; break;
		}
		a+=s[i];
	}
	rep(i,pos,sz)b+=s[i];
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	rep(i,2,60){
		st = 1;
		tmp = 0;
		dg = 1;
		for(auto j:a){
			if(rel[j]>=i){
				st = 0;
				break;
			}
			dg*=i;
			tmp+=rel[j]*dg;
		}
		tmp/=i;
		//cout<<"Base: "<<i<<" = "<<tmp<<":";
		if(tmp>23)st = 0;
		tmp = 0;
		dg = 1;
		for(auto j:b){
			if(rel[j]>=i){
				st = 0;
				break;
			}
			dg*=i;
			tmp+=rel[j]*dg;
		}
		tmp/=i;
		//cout<<tmp<<" "<<"Res: "<<st<<endl;
		if(tmp>59)st = 0;
		id[i] = st;
	}
	if(id[60])return cout<<-1,0;
	rep(i,2,60)ans+=id[i];
	if(!ans)cout<<0;
	else {
		rep(i,2,60)if(id[i])cout<<i<<" ";
	}
    return 0;
}