#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=100005;
const int MOD=1000000000 + 7;
ll n,x[1000],mx,pos;
string s;
char a,b;
int main(){
	cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>s;
	rep(i,0,n-2){
		x[(s[i]-'A')*26+(s[i+1]-'A')]++;
	}
	rep(i,0,999)if(mx<x[i])mx=x[i], pos=i;
	a=(pos/26)+'A'; b=(pos%26)+'A';
	cout<<a<<b<<endl;
	return 0;
}