#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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
const int MAX=1e7;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,m,x,l,r,prime[500],cnt,y[MAX+5];
bool prima[MAX+5];

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //memset(prima,1,sizeof prima);
    //prima[0] = prima[1] = 0;
    for(int i = 2;i*i<=MAX;i++){
    	if(!prima[i]){
    		prime[++cnt] = i;
    		for(int j = i*i;j<=MAX;j+=i)prima[j] = 1;
		}
	}
	cin>>n;
	while(n--){
		cin>>x;
		rep(i,1,cnt){
			if(x==1)break;
			if(x%prime[i]==0){
				y[prime[i]]++;
				while(x%prime[i]==0)x/=prime[i];
			}
			if(!prima[x]){
				y[x]++;
				break;
			}
		}
	}
	rep(i,2,MAX)y[i]+=y[i-1];
	cin>>m;
	while(m--){
		cin>>l>>r;
		r = min(MAX,r);
		l = min(MAX,l);
		cout<<y[r]-y[l-1]<<endl;
	}
    return 0;
}