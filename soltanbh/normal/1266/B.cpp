#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i<b;i+=2)
#define ll long long
#define pb push_back
ll n,x;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x;
		if(x%14<=6 && x>14 && x/7*7!=x) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}