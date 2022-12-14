#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=85;
int n,l[N],r[N],id[N],cnt,left;
double pl[N],pr[N],pm[N],ret[N][N][N];
void add(double pre[N][N],double nxt[N][N],int x){
	for(int i=0;i<cnt;i++)
		for(int j=0;i+j<cnt;j++)
			nxt[i][j]=0;
	for(int i=0;i<cnt;i++)
		for(int j=0;i+j<cnt;j++){
			nxt[i+1][j]+=pre[i][j]*pl[x];
			nxt[i][j+1]+=pre[i][j]*pm[x];
			nxt[i][j]+=pre[i][j]*pr[x];
		}
}
void add(double pre[N][N],double nxt[N][N],int l,int r){
	static double tmp[N][N];
	for(int i=0;i<cnt;i++)
		for(int j=0;i+j<cnt;j++)
			tmp[i][j]=pre[i][j];
	for(int x=l;x<=r;x++){
		add(tmp,nxt,x);
		for(int i=0;i<cnt;i++)
			for(int j=0;i+j<cnt;j++)
				tmp[i][j]=nxt[i][j];
	}
}
void solve(int l,int r,double dp[N][N]){
	if(l==r){
		for(int i=0;i<cnt;i++)
			for(int j=0;i+j<cnt;j++)
				ret[id[l]][left+i][j]+=pm[l]*dp[i][j];
		return;
	}
	double tmp[N][N];
	int mid=l+r>>1;
	add(dp,tmp,l,mid);
	solve(mid+1,r,tmp);
	add(dp,tmp,mid+1,r);
	solve(l,mid,tmp);
}
void calc(int ql,int qr){
	cnt=left=0;
	for(int i=0;i<n;i++)
		if(l[i]<=ql&&qr<=r[i]){
			id[cnt]=i;
			pm[cnt]=1.0*(qr-ql)/(r[i]-l[i]);
			pl[cnt]=1.0*(ql-l[i])/(r[i]-l[i]);
			pr[cnt]=1.0*(r[i]-qr)/(r[i]-l[i]);
			cnt++;
		}else if(r[i]<=ql)left++;
	if(cnt==0)return;
	static double dp[N][N];
	for(int i=0;i<cnt;i++)
		for(int j=0;i+j<cnt;j++)
			dp[i][j]=0;
	dp[0][0]=1;
	solve(0,cnt-1,dp);
}
int main(){
	scanf("%d",&n);
	vector<int>v;
	for(int i=0;i<n;i++){
		scanf("%d%d",l+i,r+i);
		v.push_back(l[i]),v.push_back(r[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i+1<v.size();i++)
		calc(v[i],v[i+1]);
	for(int i=0;i<n;i++){
		static double ans[N];
		for(int j=0;j<n;j++)ans[j]=0;
		for(int j=0;j<n;j++)
			for(int k=0;k<n-j;k++)
				for(int l=0;l<=k;l++)
					ans[j+l]+=ret[i][j][k]/(k+1);
		for(int j=0;j<n;j++)
			printf("%.10f%c",ans[j]," \n"[j+1==n]);
	}
}