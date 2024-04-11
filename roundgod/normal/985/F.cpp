#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define BASE1 19260817
#define BASE2 998244353
#define MOD1 1000000007
#define MOD2 1000000009
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str;
int _hash1[26][MAXN],_hash2[26][MAXN];
int powmod1[MAXN],powmod2[MAXN];
int save1[2][26],save2[2][26];
int main()
{
	scanf("%d%d",&n,&m);
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			_hash1[j][i]=(1LL*_hash1[j][i-1]*BASE1+((str[i-1]-'a'==j)?1:0))%MOD1;
			_hash2[j][i]=(1LL*_hash2[j][i-1]*BASE2+((str[i-1]-'a'==j)?1:0))%MOD2;
		}
	}
	powmod1[0]=powmod2[0]=1;
	for(int i=1;i<=n;i++)
	{
		powmod1[i]=(1LL*powmod1[i-1]*BASE1)%MOD1;
		powmod2[i]=(1LL*powmod2[i-1]*BASE2)%MOD2;
	}
	int x,y,len;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&len);
		for(int j=0;j<26;j++)
		{
			save1[0][j]=((_hash1[j][x+len-1]-(1LL*_hash1[j][x-1]*powmod1[len]))%MOD1+MOD1)%MOD1;
			save1[1][j]=((_hash2[j][x+len-1]-(1LL*_hash2[j][x-1]*powmod2[len]))%MOD2+MOD2)%MOD2;
			save2[0][j]=((_hash1[j][y+len-1]-(1LL*_hash1[j][y-1]*powmod1[len]))%MOD1+MOD1)%MOD1;
			save2[1][j]=((_hash2[j][y+len-1]-(1LL*_hash2[j][y-1]*powmod2[len]))%MOD2+MOD2)%MOD2;
		}
		sort(save1[0],save1[0]+26);sort(save1[1],save1[1]+26);
		sort(save2[0],save2[0]+26);sort(save2[1],save2[1]+26);
		bool f=true;
		for(int i=0;i<26;i++) if(save1[0][i]!=save2[0][i]||save1[1][i]!=save2[1][i]) {f=false; break;}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}