#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
int n;
int len[100010];
string str[100010];
int lenp,lens;
char pre,suf;
int ans;
bool f;
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>str[i],len[i]=str[i].length();
	lenp=1,pre=str[n][0];
	for(int i=1;i<len[n];++i){
		if(str[n][i]==pre) ++lenp;
		else break ;
	}
	lens=1,suf=str[n][len[n]-1];
	for(int i=len[n]-2;i>=0;--i){
		if(str[n][i]==suf) ++lens;
		else break ;
	}
	if(lenp!=len[n]) f=1;
	for(int i=0;i<len[n];++i){
		int l;
		int j=i;
		while(str[n][j+1]==str[n][i]) ++j;
		l=j-i+1;
		ans=max(ans,l);
		i=j;
	}
	for(int i=n-1;i>=1;--i){//front   back
		if(f){
			for(int j=0;j<len[i];++j){
				ans=max(ans,1+(str[i][j]==pre?lenp:0)+(str[i][j]==suf?lens:0));
			}
		}
		else{
			for(int j=0;j<len[i];++j){
				int l,k=j;
				while(str[i][k+1]==str[i][j]) ++k;
				l=k-j+1;
				ans=max(ans,str[i][j]==pre?lenp*(l+1)+l:1);
			}
			int p=0;
			while(str[i][p]==pre) ++p;
			int q=len[i]-1;
			while(str[i][q]==suf) --q;
			lenp=1ll*lenp*(p+1)+p;
			lens=1ll*lens*(len[i]-q)+(len[i]-q-1);
			if(p!=len[i]) f=1;
		}
	}
	cout<<ans<<"\n";
}