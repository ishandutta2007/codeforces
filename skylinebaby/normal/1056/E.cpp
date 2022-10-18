#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[123456];
char t[1234567];
int prime[8];
int hhash[1234567];
int iso[1234567];
int qq;
int pw(int d,int s)
{
	int p = prime[d];
	if(s==0) return 1;
	if(s&1) return (qq*pw(d,s-1))%p;
	int v = pw(d,s/2);
	return (v*v)%p;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> s;
	cin >> t;
	int k = strlen(t);
	prime[0] = 1e9+7ll;
	prime[1] = 1e9+9ll;
	prime[2] = 16769023ll;	
	prime[3] = 39916801ll;
	prime[4] = 18181ll;
	int x = 0, y = 0;
	int pos = strlen(s);
	for(int i = 0;i<strlen(s);i++)
	{
		if(s[i]==s[0]) x++;
		else {
			y++;
			pos = min(pos,i);
		}
	}
	//printf("%lld %lld %lld\n",x,y,pos);
	int d = 2;
	while(d-->0)
	{
		hhash[0] = 0;
		qq = rand()%200;
		qq += 100;
		//printf("prime = %lld qq = %lld\n",prime[d],qq);
		for(int m = 1;m<=k;m++)
		{
			hhash[m] = hhash[m-1]*qq + t[m-1]-'a' + 1;
			hhash[m]%= prime[d];
			//printf("%lld\n",hash[m]);
		}
		for(int i = 1;i<k/x;i++)
		{
			if((k-i*x)%y!=0) continue;
			int j = (k-i*x)/y; 
			int ii = pw(d,i);
			int jj = pw(d,j);
			int hhash1 = hhash[i];
			int hhash2 = hhash[pos*i+j] - hhash[pos*i]*jj;
			hhash2 = (hhash2%prime[d])+prime[d];
			hhash2%= prime[d];
			//printf("i = %lld\n hash = %lld %lld\n",i,hash1,hash2);
			if(hhash1 == hhash2) iso[i]++;
			int need = 0;
			for(int v = 0;v<strlen(s);v++)
			{
				if(v)need*= s[v]==s[0]? ii : jj;
				need+= s[v]==s[0]? hhash1:hhash2;	
				need = (need%prime[d])+prime[d];
				need%= prime[d];
				//printf("need = %lld\n",need);
			} 
			if(need==hhash[k]) iso[i]+= 10;
		}

	}	
	int ans = 0;
	for(int i = 1;i<=k;i++) if(iso[i]>=20&&iso[i]!=22) ans++;
	cout << ans;
	return 0;
}