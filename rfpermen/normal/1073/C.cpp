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
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,l[MAX],r[MAX],u[MAX],d[MAX],le,ri,mid,ans,x,y,res,dx,dy,cek;
char c;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>c;
    	if(c=='U')u[i]++;
    	else if(c=='D')d[i]++;
    	else if(c=='L')l[i]++;
    	else r[i]++;
	}
	cin>>x>>y;
	if(abs(x)+abs(y)>n||(((x+y)&1)^(n&1)))return cout<<-1,0;
	rep(i,1,n)u[i]+=u[i-1], d[i]+=d[i-1], l[i]+=l[i-1], r[i]+=r[i-1];
	dx = r[n]-l[n], dy = u[n]-d[n];
	if(dx==x&&dy==y)return cout<<0,0;
	ans = 1e9;
	rep(i,1,n){
		le = i, ri = n, res = -1;
		while(le<=ri){
			mid = (le+ri)/2;
			cek = abs(x-(dx-(r[mid]-r[i-1])+(l[mid]-l[i-1])));
			cek+= abs(y-(dy-(u[mid]-u[i-1])+(d[mid]-d[i-1])));
			if(cek>mid-i+1)le = mid+1;
			else res = mid-i+1, ri = mid-1;
		}
		if(res!=-1)ans = min(ans,res);
	}
	cout<<ans<<endl;
    return 0;
}