#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;
	ll cool;
	ll a;
	ll b;
	ll oddmin = 10000000001;
int main() {
	cin>>b;
	FOR(i,a,b){
 	cin>>a;
 	cool+=a;
 	
 	if(a%2 == 1 && a<oddmin)
 	{
 		oddmin = a;
	}
	}
	if(cool%2 == 1)
	{
	cool = cool - oddmin;
	}
 	cout<<cool<<endl;
 
 	
	return 0;
}