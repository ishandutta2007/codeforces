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

ll a,b,tmp,cek,ans,slh,cnt,bts,bt;
unsigned ll spl;

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    spl = 10;
    while(spl<b)spl*=10;
    if(b==spl)b--;
    cek = b%10;
    tmp = b;
    bts = 1;
    while(tmp>9)tmp/=10, bts*=10;
    if(tmp<cek)b = b-cek+tmp;
    else if(tmp>cek)b = b-10-cek+tmp;
    cek = b%10;
    tmp = b;
    while(tmp>9)tmp/=10;
    if(cek!=tmp)b--;
    if(a>b)return cout<<0,0;
    bt = tmp, tmp = 1, cnt = 1;
    while(bt!=tmp || cnt!=bts){
    	if(cnt>9)ans+=cnt/10;
    	else ans++;
    	if(tmp==9)tmp = 0, cnt*=10;
    	tmp++;
	}
//	cout<<ans<<endl;
//	cout<<"---"<<bt<<" "<<bts<<endl;
//    puts("debug");
//    cout<<ans<<endl;
//	cout<<b<<endl;
	ans+=(b%cnt)/10;
	ans++;
    cek = a%10;
    tmp = a;
    bts = 1;
    while(tmp>9)tmp/=10, bts*=10;
    if(tmp>cek)a = a-cek+tmp;
    else if(tmp<cek)a = a+tmp+10-cek;
    cek = a%10;
    tmp = a;
    while(tmp>9)tmp/=10;
    if(cek!=tmp)a++;
    bt = tmp, tmp = 1, cnt = 1;
    while(bt!=tmp || cnt!=bts){
    	if(cnt>9)slh+=cnt/10;
    	else slh++;
    	if(tmp==9)tmp = 0, cnt*=10;
    	tmp++;
	}
//	cout<<a<<" "<<b<<endl;
	slh+=(a%cnt)/10;
	slh++;
//	cout<<ans<<" "<<slh<<endl;
	cout<<max(0LL,ans-slh+1)<<endl;
    return 0;
}