#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
map<char,ll> A;
map<char,ll> B;
int main()
{
	A['S']=0;A['H']=1;A['D']=2;A['C']=3;
	B['6']=0;B['7']=1;B['8']=2;B['9']=3;B['T']=4;B['J']=5;B['Q']=6;B['K']=7;B['A']=8;
	string w,e;char q;cin>>q>>w>>e;
	pll a=MP(A[w[1]],B[w[0]]),b=MP(A[e[1]],B[e[0]]);ll t=A[q];
	if((a.F==b.F&&a.S>b.S)||(a.F!=b.F&&a.F==t)) cout<<"YES";
	else cout<<"NO";
}