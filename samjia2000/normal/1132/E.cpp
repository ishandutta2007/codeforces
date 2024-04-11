#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 100;
const LL INF = 1e18;

LL L;
LL cnt[10];
LL f[N][520][50];

int main(){
	cin>>L;
	fo(i,1,8)cin>>cnt[i];
	fo(i,0,70)fo(j,0,512)fo(k,0,40)f[i][j][k]=-INF;
	f[0][0][0]=0;
	fo(w,0,59){
		int d=0;
		fo(i,1,8)
		if ((cnt[i]&(1ll<<w))>0)d|=(1<<i);
		if ((L&(1ll<<w))>0)d|=1;
		fo(u,0,255){
			LL sum=0;
			int t=0,r=0;
			fo(i,1,8){
				int v=((u&(1<<(i-1)))>0);
				sum+=v*i;
				if (v==((d&(1<<i))>0))r|=(1<<i);
				else
					if (v)t|=(1<<i);
			}
			fo(j,0,511)
				fo(k,0,40)
				if (f[w][j][k]>-INF){
						int ad=sum+k;
						int t1=t|(j&r);
						int v=ad&1;
						if (v==(d&1))t1|=(j&1);
						else if (v)t1|=1;
						f[w+1][t1][ad/2]=max(f[w+1][t1][ad/2],f[w][j][k]+sum*(1ll<<w));
				}
		}
	}
	LL ans=-INF;
	fo(k,0,40)ans=max(ans,f[60][0][k]);
	cout<<ans<<endl;
	return 0;
}