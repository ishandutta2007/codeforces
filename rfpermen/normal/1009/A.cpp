#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define point pair<double,double>
#define segment pair<point,point>
#define circle pair<point,double> //titik pusat, radius
#define line pair<double,double> //m,c
#define ins insert
#define er erase

#define FORU(a,b,c) for(int a=b; a<=c; a++)
#define FORD(a,b,c) for(int a=b; a>=c; a--)
#define FOR(a,b) for(int a=1; a<=b; a++)
#define FORA(a,b) for(auto (a) : (b))

const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;

#define yu using
#define don namespace
#define sei std

yu don sei;

int main()
{
	int n,m;
	cin>>n>>m;
	queue<int>A;
	queue<int>B;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		B.push(x);
	}
	int cnt=0;
	while(!A.empty())
	{
		if(B.empty())break;
		if(A.front()<=B.front())
		{
			B.pop();
			cnt++;
		}
		A.pop();
	}
	cout<<cnt<<endl;
	return 0;
}