#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define mod2 998244353
// 3 2 3 1 
// 0 1 2 3 
// 3 1 0 2 
// 1 3 2 1 4 1 
void solve(){
int n;cin>>n;
int index,Max = 0;
vi v(n);
rep(i,0,n)cin>>v[i];

rep(i,1,n){
	if(v[i]*v[i-1]>Max)
		Max=v[i]*v[i-1];
}
cout<<Max<<"\n";}
signed  main ()
{
	IOS;
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin>>t;
	rep(i,0,t)solve();
return 0;
}