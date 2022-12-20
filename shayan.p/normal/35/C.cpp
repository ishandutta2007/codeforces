#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define cin fin
#define cout fout
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
using namespace std;
ll manh(pll a,pll b) {return abs(a.F-b.F)+abs(a.S-b.S);}
const ll inf=1e7;
int main()
{
	pll Max=MP(1,1),tr[11];ll Maxv=-inf,M,N,t;cin>>N>>M>>t;
	for(ll i=0;i<t;i++) cin>>tr[i].F>>tr[i].S;
	for(ll i=1;i<=N;i++)
		for(ll j=1;j<=M;j++)
		{
			ll Dis=inf;
			for(ll k=0;k<t;k++) Dis=min(Dis,manh(MP(i,j),tr[k]));
			if(Dis>Maxv) {Maxv=Dis;Max=MP(i,j);}
		}
	cout<<Max.F<<" "<<Max.S;
}