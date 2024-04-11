#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=5e3+10;
ll table[maxn][maxn],p[maxn],b[maxn],Ans[maxn],ans,n;
bool exist[maxn];
void check(ll num){
	for(ll i=0;i<n;i++)exist[i]=0;
	for(ll i=0;i<n;i++){
		ll q=table[i][0] xor num;
		if(exist[q]||q>=n)return;
		exist[q]=1;
		p[i]=q;
	}
	for(ll i=0;i<n;i++)b[p[i]]=i;	
	for(ll i=0;i<n;i++){
		if(table[0][i]!=(p[0] xor b[i]))return;
	}
	ans++;
	for(ll i=0;i<n;i++)Ans[i]=p[i];
}
int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cout<<"? "<<0<<" "<<i<<endl;
		cin>>table[0][i];
	}
	for(ll i=1;i<n;i++){
		cout<<"? "<<i<<" "<<0<<endl;
		cin>>table[i][0];
	}
	for(ll i=0;i<n;i++){
		check(i);
	}
	cout<<"!\n"<<ans<<endl;
	for(ll i=0;i<n;i++)cout<<Ans[i]<<" ";
}