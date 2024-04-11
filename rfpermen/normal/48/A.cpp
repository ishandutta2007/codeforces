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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

string f,m,s;

int main(){
//	cout<<fixed<<setprecision(0);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>f>>m>>s;
    if(f=="rock"&&m=="scissors"&&m==s)cout<<'F';
    else if(f=="scissors"&&m=="paper"&&m==s)cout<<'F';
    else if(f=="paper"&&m=="rock"&&m==s)cout<<'F';
    else if(m=="rock"&&f=="scissors"&&f==s)cout<<'M';
    else if(m=="scissors"&&f=="paper"&&f==s)cout<<'M';
    else if(m=="paper"&&f=="rock"&&f==s)cout<<'M';
    else if(s=="rock"&&f=="scissors"&&f==m)cout<<'S';
    else if(s=="scissors"&&f=="paper"&&f==m)cout<<'S';
    else if(s=="paper"&&f=="rock"&&f==m)cout<<'S';
    else cout<<'?';
    return 0;
}