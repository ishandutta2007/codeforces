#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int k,n,m;

char solve(){
	cin>>n>>m;
	m--;
	n--;
	int mn=min(m,n);
	int b=(abs(m-n))%2;
	mn=mn%(2*k+2);
	if(mn==k || mn==2*k+1)
		return '+';
//	cout<<"!";
	if(k==1)
		return (b) ? '+' : '-';
	return ( (mn<k) ^ (b) ) ? '-' : '+';
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int x;
	cin>>x>>k;
	forn(i,x)
		cout<<solve()<<endl;
	return 0;
}