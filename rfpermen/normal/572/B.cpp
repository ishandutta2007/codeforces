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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,k,x,y,a;
int s[MAX],b[MAX];
vector<pii> ans;
char c;

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    while(n--){
    	cin>>c>>x>>y;
    	if(c=='B')b[x]+=y;
    	else s[x]+=y;
	}
	rep(i,0,100000){
		if(!s[i])continue;
		ans.pb({i,s[i]});
		if(++a==k)break;
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)cout<<"S "<<i.fi<<" "<<i.se<<endl;
	a = 0;
	rap(i,100000,0){
		if(!b[i])continue;
		cout<<"B "<<i<<" "<<b[i]<<endl;
		if(++a==k)break;
	}
    return 0;
}