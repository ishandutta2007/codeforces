#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
inline int in() { int x; scanf("%d", &x); return x;}
int main()
{
	int n,k,t;
	cin>>n>>k>>t;
	int f=max(t-k,0);
	int l=min(t,n);
	cout<<l-f;
}