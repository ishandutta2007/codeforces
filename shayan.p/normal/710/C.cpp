#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll mat[200][200],n;
inline ll hf(ll num){
	return num+(n/2);
}
void Do(ll num){
	ll x=((num%2)==0);
	for(ll i=-num;i<=num;i++)mat[hf(num)][hf(i)]=(x++)%2;
	x=((num%2)==0);
	for(ll i=-num;i<=num;i++)mat[hf(-num)][hf(i)]=(x++)%2;
	x=((num%2)==0);
	for(ll i=-num;i<=num;i++)mat[hf(i)][hf(num)]=(x++)%2;
	x=((num%2)==0);
	for(ll i=-num;i<=num;i++)mat[hf(i)][hf(-num)]=(x++)%2;
}
int main(){
	cin>>n;
	ll f=0;
	ll z=0;
	for(ll i=0;i<=(n/2);i++){
		Do(i);
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(mat[i][j]==1){
				cout<<2*(++f)-1<<" ";
			}
			else{
				cout<<2*(++z)<<" ";
			}
		}
		cout<<endl;
	}
}