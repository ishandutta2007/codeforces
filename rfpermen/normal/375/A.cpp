#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,k,cnt[10],tmp,res[7];
vector<int> v;
string s;

int main(){
	cout<<fixed<<setprecision(6);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    v.pb(1), v.pb(6), v.pb(8), v.pb(9);
    do{
    	k = 0;
    	for(auto i:v)k = k*10+i;
    	res[k%7] = k;
	}while(next_permutation(v.begin(),v.end()));
//	rep(i,0,6)cout<<res[i]<<endl;
	cin>>s;
	for(auto i:s)cnt[i-'0']++;
	cnt[1]--, cnt[6]--, cnt[8]--, cnt[9]--;
	rep(i,1,9){
		while(cnt[i]--){
			tmp = (tmp*10+i)%7;
			cout<<i;
		}
	}
	tmp = (tmp*10000)%7;
	tmp = (7-tmp)%7;
	cout<<res[tmp];
	while(cnt[0]--)cout<<0;
    return 0;
}