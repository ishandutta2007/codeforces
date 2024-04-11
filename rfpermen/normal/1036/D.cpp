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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
const ll MAX=3e5+5;
const int MOD=1000000000 + 7;
const ll INF=2e18;
const int nr[]={1,-1,0,0,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

ll n,m,x[MAX],y[MAX],a,b,id1,id2,cnt;

int main(){
    //cout<<fixed<<setprecision(3);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], a+=x[i];
    cin>>m;
    rep(i,1,m)cin>>y[i], b+=y[i];
    if(a!=b)return cout<<-1,0;
    id1 = id2 = 1;
    while(id1<=n && id2<=m){
    	if(x[id1]==y[id2])cnt++, id1++, id2++;
    	else if(x[id1]<y[id2])x[id1+1]+=x[id1], id1++;
    	else y[id2+1]+=y[id2], id2++;
	}
	cout<<cnt<<endl;
    return 0;
}