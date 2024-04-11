#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int m,k,a[1005][1005],s[1005],s2[1005];
signed main(){
	m=read();k=read();
	int d=0,cnt=0;
	for(int i=0;i<k;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
			s[i]+=a[i][j];
			s2[i]+=a[i][j]*a[i][j];
		}
		if(i){
			if(!cnt)d=s[i]-s[i-1],cnt=1;
			else if(d==s[i]-s[i-1])cnt++;
			else cnt--;
		}
	}	
	for(int i=0;i<k-1;++i)
		if(s[i+1]-s[i]!=d){
			printf("%lld ",i+1);
			int p=(i>=2)?0:i+2,ad=d-(s[i+1]-s[i]);
			int v2=(s2[p+2]+s2[p]-s2[p+1]*2)/2;
			int o=(i+1<k-1)?i+1:i;
			for(int j=1;j<=m;++j){
				s2[i+1]+=ad*ad+a[i+1][j]*ad*2;
				if(s2[o]*2+v2*2==s2[o-1]+s2[o+1]){
					printf("%lld\n",a[i+1][j]+ad);
					return 0;
				}
				s2[i+1]-=ad*ad+a[i+1][j]*ad*2;
			}
			return 0;
		}
	return 0;
}