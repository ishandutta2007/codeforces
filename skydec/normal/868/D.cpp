#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=205;
bool pre[N][20];
bool suf[N][20];
int len[N];
bitset<1<<16>hav[N][17];
int n,m;
char s[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s+1);
		len[i]=strlen(s+1);
		rep(l,1,16)rep(j,1,len[i]-l+1){
			int x=0;
			rep(d,j,j+l-1){
				x<<=1;
				x|=(s[d]=='1');
			}
			hav[i][l][x]=1;
		}
		rep(j,1,min(16,len[i]))pre[i][j]=(s[j]-'0'),suf[i][j]=(s[len[i]-j+1]-'0');
	}
	scanf("%d",&m);
	rep(Q,1,m){
		int a,b;scanf("%d%d",&a,&b);
		len[n+Q]=min(len[a]+len[b],1000);
		rep(l,1,16){
			hav[n+Q][l]=hav[a][l]|hav[b][l];
			rep(k,1,min(len[a],l-1))if(l-k<=len[b]){
				int x=0;
				per(d,k,1){
					x<<=1;
					x|=suf[a][d];
				}
				rep(d,1,l-k){
					x<<=1;
					x|=pre[b][d];
				}
				hav[n+Q][l][x]=1;
			}
		}

		rep(i,1,min(len[b],16))suf[n+Q][i]=suf[b][i];
		if(len[b]<16)rep(i,1,min(16-len[b],len[a]))suf[n+Q][i+len[b]]=suf[a][i];

		rep(i,1,min(len[a],16))pre[n+Q][i]=pre[a][i];
		if(len[a]<16)rep(i,1,min(16-len[a],len[b]))pre[n+Q][i+len[a]]=pre[b][i];

		int ans=0;
		rep(i,1,16)if(hav[n+Q][i].count()<(1<<i)){
			break;
		}
		else ans=i;
		printf("%d\n",ans);
	}
	return 0;
}