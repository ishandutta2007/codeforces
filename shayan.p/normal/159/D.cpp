#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e3+10;
bool pal[maxn][maxn];
string s;
ll st[maxn],en[maxn],tot,vis;
int main(){
	cin>>s;
	for(ll i=0;i<s.size();i++){
		pal[i][i]=1;
		st[i]++;
		en[i]++;
		tot++;
		if(i-1>=0){
			pal[i-1][i]=(s[i]==s[i-1]);
			st[i-1]+=pal[i-1][i];
			en[i]+=pal[i-1][i];
			tot+=pal[i-1][i];
		}
		for(ll j=i-2;j>=0;j--){
			pal[j][i]=pal[j+1][i-1]&&(s[j]==s[i]);
			st[j]+=pal[j][i];
			en[i]+=pal[j][i];
			tot+=pal[j][i];
		}
	}
	ll ans=0;
	for(ll i=0;i<s.size();i++){
		vis+=st[i];
		ans+=en[i]*(tot-vis);
	}
	cout<<ans;
}