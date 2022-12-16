#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
using namespace std;
map<char,int> mp;
ll score[3];
int main()
{
	mp['A']=0;mp['B']=1;mp['C']=2;
	string s[3];cin>>s[0]>>s[1]>>s[2];
	for(ll i=0;i<3;i++) ((s[i][1]=='<')?score[mp[s[i][2]]]:score[mp[s[i][0]]])++;
	pair<ll,char> ans[3];
	for(ll i=0;i<3;i++) ans[i]=MP(score[i],'A'+i);
	sort(ans,ans+3);
	for(ll i=0;i<3;i++) if(ans[i].F!=i) {cout<<"Impossible";return 0;}
	for(ll i=0;i<3;i++) cout<<ans[i].S;
}