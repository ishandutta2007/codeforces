#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000+19;

ll f[N][N],res;
int rk[N][N],seq[N][N],Q[N],sum[N][10],h[N],len[N],cnt[20],val[10];
int n,top,m;
string s,t[N];

void Upd(ll &x,ll y){
	if (y>x) x=y;
}
string getstr(){
	static char s[N];
	scanf("%s",s);
	int len=strlen(s);
	reverse(s,s+len);
	return string(s);
}
void Work(int w,int chk){
	memset(h,0,sizeof(h));
	memset(sum,0,sizeof(sum));
	if (w){
		For(i,1,n+1){
			For(j,0,10) sum[i][j]=sum[i-1][j]+(t[seq[w-1][i]][w]==j+'0');
			h[i]=h[i-1]+(w>=len[seq[w-1][i]]);
		}
	} else{
		For(i,1,n+1){
			For(j,0,10) sum[i][j]=sum[i-1][j]+(t[i][w]==j+'0');
			h[i]=h[i-1]+(w>=len[i]);
		}
	}
	For(i,0,n+1)
		if (f[w][i]>=0){
			for (int c=(w==top-1);c<10;c++)
				if (s[w]=='?'||s[w]==c+'0'){
					ll tmp=0;
					int num=0;
					For(d,0,10){
						tmp+=1ll*(sum[n][d]-sum[n-i][d])*val[(d+c+1)%10];
						tmp+=1ll*sum[n-i][d]*val[(d+c)%10];
						num+=(d+c+1>=10)*(sum[n][d]-sum[n-i][d]);
						num+=(d+c>=10)*sum[n-i][d];
					}
					if (chk) tmp-=1ll*h[n-i]*val[0];
					Upd(f[w+1][num],f[w][i]+tmp);
				}
		}
}

int main(){
	s=getstr();
	top=s.length();
	m=max(m,int(s.length()));
	n=IN();
	For(i,1,n+1){
		t[i]=getstr();
		len[i]=t[i].length();
		m=max(m,len[i]);
	}
	For(i,0,10) val[i]=IN();
	while (s.length()<m) s+="0";
	For(i,1,n+1){
		while (t[i].length()<m) t[i]+="0";
	}
	For(i,1,n+1) Q[i]=i;
	For(w,0,m){
		memset(cnt,0,sizeof(cnt));
		For(i,1,n+1) cnt[t[i][w]-'0']++;
		For(i,1,10) cnt[i]+=cnt[i-1];
		for (int i=n;i;i--){
			seq[w][cnt[t[Q[i]][w]-'0']--]=Q[i];
		}
		For(i,1,n+1) Q[i]=seq[w][i];
	}
	For(i,0,N) For(j,0,N) f[i][j]=-(1ll<<60);
	f[0][0]=0;
	For(w,0,top) Work(w,0);
	For(w,top,m) Work(w,1);
	For(i,0,n+1){
		Upd(res,f[m][i]+1ll*i*val[1]);
	}
	cout<<res<<endl;
}