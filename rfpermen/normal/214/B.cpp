#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,d[10],a,tot;
bool st;

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>a, d[a]++, tot+=a;
    if(!d[0])return cout<<-1,0;
    if(tot%3==1){
    	for(int i=1;i<=9;i+=3)while(tot%3 && d[i])d[i]--, tot-=i;
		for(int i=2;i<=9;i+=3)while(tot%3 && d[i])d[i]--, tot-=i;
	}
	else if(tot%3==2){
		for(int i=2;i<=9;i+=3)while(tot%3 && d[i])d[i]--, tot-=i;
		for(int i=1;i<=9;i+=3)while(tot%3 && d[i])d[i]--, tot-=i;
	}
	rap(i,9,1)while(d[i]--)cout<<i,st=1;
	if(st)while(d[0]--)cout<<0;
	else cout<<0;
    return 0;
}