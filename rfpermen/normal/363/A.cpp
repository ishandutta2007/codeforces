#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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

ll n,k,a,b,c,x,y,z,sz[4],T,res,cnt;
string s,t;
bool st;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x;
    if(x==0)cout<<"O-|-OOOO"<<endl;
    while(x){
    	if(x%10==0)cout<<"O-|-OOOO"<<endl;
    	else if(x%10==1)cout<<"O-|O-OOO"<<endl;
    	else if(x%10==2)cout<<"O-|OO-OO"<<endl;
    	else if(x%10==3)cout<<"O-|OOO-O"<<endl;
    	else if(x%10==4)cout<<"O-|OOOO-"<<endl;
    	else if(x%10==5)cout<<"-O|-OOOO"<<endl;
    	else if(x%10==6)cout<<"-O|O-OOO"<<endl;
    	else if(x%10==7)cout<<"-O|OO-OO"<<endl;
    	else if(x%10==8)cout<<"-O|OOO-O"<<endl;
    	else if(x%10==9)cout<<"-O|OOOO-"<<endl;
    	x/=10;
	}
    return 0;
}