#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<N;i++)
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
const int MAX=6e5+5;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

struct nn{
	int arr[3];
	bool eow;
}trie[MAX];

int n,m,k,sz;
bool cek[MAX],st;
string s;

void add(int nw,int nx){
	if(nx==sz){
		trie[nw].eow = 1;
		return;
	}
	if(!trie[nw].arr[s[nx]])trie[nw].arr[s[nx]] = ++k;
	
	add(trie[nw].arr[s[nx]],nx+1);
	return;
}

void search(int nw,int nx,bool us){
	if(st)return;
	if(nx==sz){
		if(us)st = 1;
		return;
	}
	if(us){
		if(!trie[nw].arr[s[nx]])return;
		search(trie[nw].arr[s[nx]],nx+1,1);
	}
	else {
		if(trie[nw].arr[0]){
			if(s[nx]==0)search(trie[nw].arr[0],nx+1,0);
			else search(trie[nw].arr[0],nx+1,1);
		}
		if(trie[nw].arr[1]){
			if(s[nx]==1)search(trie[nw].arr[1],nx+1,0);
			else search(trie[nw].arr[1],nx+1,1);
		}
		if(trie[nw].arr[2]){
			if(s[nx]==2)search(trie[nw].arr[2],nx+1,0);
			else search(trie[nw].arr[2],nx+1,1);
		}
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(n--){
    	cin>>s;
    	sz = s.size();
    	rep(i,0,sz)s[i]-='a';
    	cek[sz] = 1;
    	add(0,0);
	}
	while(m--){
		cin>>s;
		sz = s.size();
		if(!cek[sz]){
			cout<<"NO\n"; continue;
		}
    	rep(i,0,sz)s[i]-='a';
    	st = 0;
    	search(0,0,0);
    	if(st)cout<<"YES\n";
    	else cout<<"NO\n";
	}
    return 0;
}