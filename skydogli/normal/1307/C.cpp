#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
char ch[MN];
int sum[MN][26];
LL cnt[27][27];
int main(){
	scanf("%s",ch+1);
	int len=strlen(ch+1);
	for(int i=len;i;--i){
		for(int j=0;j<26;++j)sum[i][j]=sum[i+1][j];
		sum[i][ch[i]-'a']++;
	}
	for(int i=1;i<=len;++i){
		cnt[ch[i]-'a'][26]++;
		for(int j=0;j<26;++j)
			cnt[ch[i]-'a'][j]+=sum[i+1][j];
	}
	LL ans=0;
	for(int i=0;i<26;++i)
		for(int j=0;j<=26;++j)
			ans=max(ans,cnt[i][j]);
	printf("%lld\n",ans);
	return 0;
}