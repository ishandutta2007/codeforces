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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int sz,mx,d,mn,y;
string s,ans;
map<string,int> m;

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    rep(i,9,sz){
    	if(s[i-9]!='-' && s[i-8]!='-' && s[i-7]=='-' && s[i-6]!='-' && s[i-5]!='-' 
		&& s[i-4]=='-' && s[i-3]!='-' && s[i-2]!='-' && s[i-1]!='-' && s[i]!='-' ){
			d = (s[i-9]-'0')*10 + (s[i-8]-'0');
			mn= (s[i-6]-'0')*10 + (s[i-5]-'0');
			if(d==0)continue;
			if(mn==1 || mn==3 || mn==5 || mn==7 || mn==8 || mn==10 || mn==12){
				if(d>31)continue;
			}
			else if(mn==4 || mn==6 || mn==9 || mn==11){
				if(d>30)continue;
			}
			else if(mn==2){
				if(d>28)continue;
			}
			else continue;
			y = (s[i-3]-'0')*1000 + (s[i-2]-'0')*100 + (s[i-1]-'0')*10 + (s[i]-'0');
			if(y<2013 || y>2015)continue;
			ans = s[i-9];
			ans+= s[i-8];
			ans+= s[i-7];
			ans+= s[i-6];
			ans+= s[i-5];
			ans+= s[i-4];
			ans+= s[i-3];
			ans+= s[i-2];
			ans+= s[i-1];
			ans+= s[i];
			m[ans]++;
		}
	}
	for(auto i:m)if(mx<i.se)mx = i.se, ans=i.fi;
	cout<<ans<<endl;
    return 0;
}