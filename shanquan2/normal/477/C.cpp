#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct st{
	int s,t;
	bool operator <(const st &o)const{
		return t<o.t || t==o.t && s<o.s;
	}
}q[2010],chosen[2010];
bool cmp(const st &x,const st &y){
	return x.t-x.s<y.t-y.s;
}
char s[2010],p[510];
int top=0,dp[2010][2010],len[2010],q1[2010][2010],qt[2010],la[2010];

int ind(int x){
	return x&(-x);
}

void change(int x,int y,int r){
	while(y<2010){
		q1[x][y]=min(q1[x][y],r);
		y+=ind(y);
	}
	return;
}

int query(int x,int y){
	int ans=2010;
	while(y>0){
		ans=min(ans,q1[x][y]);
		y-=ind(y);
	}
	return ans;
}

int main(){
	scanf("%s%s",s,p);
	int n=strlen(s),m=strlen(p);
	for(int i=0;i<n;i++)if(s[i]==p[0]){
		int j=1,k;
		for(k=i+1;k<n && j<m;k++)
			if(s[k]==p[j])j++;
		if(j==m){
			q[top].s=i;
			q[top++].t=k-1;
		}
	}
	sort(q,q+top);
	for(int i=0;i<top;i++)la[i]=q[i].t;
	sort(la,la+top);
	int lt=unique(la,la+top)-la;
//	for(int i=0;i<top;i++)printf("%d %d\n",q[i].s,q[i].t);printf("\n");


	for(int i=0;i<=top;i++)for(int j=0;j<=top;j++)dp[i][j]=q1[i][j]=len[i]=2010;
	dp[0][1]=q[0].t-q[0].s-m+1;
	int u=lower_bound(la,la+lt,q[0].t)-la;
	change(1,u+1,dp[0][1]);
	for(int i=1;i<top;i++){
		dp[i][1]=q[i].t-q[i].s-m+1;
		int u=lower_bound(la,la+lt,q[i].t)-la;
		change(1,u+1,dp[i][1]);
		u=lower_bound(la,la+lt,q[i].s)-la-1;
		if(u==0 && q[i].s-1<la[0])continue;
		for(int j=2;j<=top;j++){
			dp[i][j]=query(j-1,u+1)+q[i].t-q[i].s-m+1;
			int u1=lower_bound(la,la+lt,q[i].t)-la;
			change(j,u1+1,dp[i][j]);
		}
	}
/*	for(int i=0;i<top;i++){
		for(int j=0;j<=top;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}*/
	for(int i=0;i<top;i++)for(int j=1;j<=top;j++){
		len[j]=min(len[j],dp[i][j]);
	}
//	for(int i=0;i<=2010;i++)printf("%d ",len[i]);printf("\n\n");
	int ans=1;
	while(len[ans]<2010 && ans<=top)ans++;ans--;
	if(ans==0){
		for(int i=0;i<n;i++)printf("0 ");printf("0\n");
		return 0;
	}
	
	for(int i=0;i<len[1];i++)if(i<n)printf("0 ");else printf("0\n");
	for(int i=2;i<=ans;i++){
		for(int j=len[i-1];j<len[i];j++)if(j<n)printf("%d ",i-1);else printf("%d\n",i-1);
	}
	for(int i=len[ans];i<=n-m*ans;i++)if(i<n)printf("%d ",ans);else printf("%d\n",ans);
	for(int i=ans;i>0;i--)
		for(int j=n-i*m+1;j<=n-m*i+m;j++)if(j<n)printf("%d ",i-1);else printf("%d\n",i-1);
	return 0;
}