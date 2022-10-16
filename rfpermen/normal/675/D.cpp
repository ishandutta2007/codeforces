#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
const int MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,y;
set<int> x,z,le,ri;
set<int>::iterator lw,up;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>y;
    x.insert(y);
    z.insert(-y);
    while(--n){
    	cin>>y;
    	lw = z.upper_bound(-y);
    	up = x.upper_bound(y);
//    	cout<<"\n----\n";
//    	if(lw!=z.end())cout<<*lw<<endl; else cout<<"Kosong\n";
//    	if(up!=x.end())cout<<*up<<endl; else cout<<"Kosong\n";cout<<"----\n";
    	if(lw!=z.end()&&!le.count(*lw))cout<<-*lw<<" ", le.insert(*lw);
    	else cout<<*up<<" ", ri.insert(*up);
   		x.insert(y);
    	z.insert(-y);
	}
    return 0;
}