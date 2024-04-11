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
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,sz;
string s;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n; cin.ignore(1);
    while(n--){
    	getline(cin,s);
    	sz = s.size()-1;
    	if(sz<4)cout<<"OMG>.< I don't know!\n";
    	else if(s[0]=='m'&&s[1]=='i'&&s[2]=='a'&&s[3]=='o'&&s[4]=='.'&&
				s[sz-4]=='l'&&s[sz-3]=='a'&&s[sz-2]=='l'&&s[sz-1]=='a'&&s[sz]=='.')cout<<"OMG>.< I don't know!\n";
		else if(s[0]=='m'&&s[1]=='i'&&s[2]=='a'&&s[3]=='o'&&s[4]=='.')cout<<"Rainbow's\n";
		else if(s[sz-4]=='l'&&s[sz-3]=='a'&&s[sz-2]=='l'&&s[sz-1]=='a'&&s[sz]=='.')cout<<"Freda's\n";
		else cout<<"OMG>.< I don't know!\n";
		
	}
    return 0;
}