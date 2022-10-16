#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define rep(i,n,N) for(int i = n; i<=N; i++)
#define rap(i,n,N) for(int i = n; i>=N; i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pb push_back
#define pob pop_back
#define endl '\n'
const int MAX = 1e5+5;
const int MOD = 1000000000+7;

int n,m,rem,nw,nex;
bool vis[501][5001];
queue<pair<string,pii>>  q;
pair<string,pii> cur;
string s,nx;
char c;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	q.push({"",{0,m}});
	vis[0][m] = 1;
	while(!q.empty()){
		cur = q.front(); q.pop();
		nw = cur.sf, rem = cur.ss;
		s = cur.fi;
		if(!rem&&!nw)return cout<<s<<endl,0;
		rep(i,0,9){
			c = '0'+i;
			if(i>rem)break;
			nex = (nw*10+i)%n;
			if(vis[nex][rem-i])continue;
			vis[nex][rem-i] = 1;
			q.push({s+c,{nex,rem-i}});
		}
	}
	cout<<"-1\n";
	return 0;
}