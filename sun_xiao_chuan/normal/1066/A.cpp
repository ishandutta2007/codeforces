#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,c,d,res;


int main() {
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		res=a/b-d/b+(c-1)/b;
		cout<<res<<'\n';
	}
}