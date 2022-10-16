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

int n,m,x,y,z,sz,cnt,tmp,res,a[128],b,k;
string s,t;
char c[MAX];

int main(){
//	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	if(n%4)return cout<<"===",0;
	cin>>s;
	for(auto i:s)a[i]++;
	n/=4;
	if(a['A']>n||a['C']>n||a['G']>n||a['T']>n)return cout<<"===",0;
	sz = s.size()-1;
	rep(i,0,sz){
		if(s[i]=='?'){
			if(a['A']!=n)s[i] = 'A', a['A']++;
			else if(a['C']!=n)s[i] = 'C', a['C']++;
			else if(a['G']!=n)s[i] = 'G', a['G']++;
			else if(a['T']!=n)s[i] = 'T', a['T']++;
		}
	}
	cout<<s;
    return 0;
}