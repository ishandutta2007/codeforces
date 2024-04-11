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
#define plll pair<pll,ll>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0};
const int dc[]={0,1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int id,len;
bool st;
string s[7],ans[MAX],cmp[MAX];

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("rekreasi_7.in", "r", stdin);
//	freopen("rekreasi_7.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,6)cin>>s[i];
    sort(s+1,s+7);
    do {
    	if(	s[1][0]!=s[2][0]||s[1].back()!=s[3][0]||s[2].back()!=s[4][0]||
			s[3].back()!=s[5][0]||s[4].back()!=s[6][0]||s[5].back()!=s[6].back()||
			s[2].size()>=s[3].size()||s[1].size()>=s[4].size()||s[3][s[2].size()-1]!=s[4][s[1].size()-1]||
			s[1].size()+s[5].size()-1!=s[4].size()||s[2].size()+s[6].size()-1!=s[3].size())continue;
		rep(i,1,s[3].size()){
			cmp[i].clear();
			rep(j,1,s[4].size())cmp[i].pb('.');
		}
		id = 0;
		for(auto i:s[1])cmp[1][id++] = i;
		id = 0;
		for(auto i:s[2])cmp[++id][0] = i;
		id = 0;
		for(auto i:s[3])cmp[++id][s[1].size()-1] = i;
		id = 0;
		for(auto i:s[4])cmp[s[2].size()][id++] = i;
		id = s[1].size()-1;
		for(auto i:s[5])cmp[s[3].size()][id++] = i;
		id = s[2].size()-1;
		for(auto i:s[6])cmp[++id][s[4].size()-1] = i;
		if(!st){
			rep(i,1,s[3].size())ans[i] = cmp[i];
			len = s[3].size();
			st = 1;
		}
		else {
			rep(i,1,s[3].size()){
				if(cmp[i]<ans[i]){
					rep(j,1,s[3].size())ans[j] = cmp[j];
					len = s[3].size();
					break;
				}
				else if(cmp[i]>ans[i])break;
			}
		}
	}while(next_permutation(s+1,s+7));
	if(!st)cout<<"Impossible\n";
	else rep(i,1,len)cout<<ans[i]<<endl;
	return 0;
}