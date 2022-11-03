#include<bits/stdc++.h>
using namespace std;

const int N=5005;
char s[N];
int n,b[N][N],d[N][N],e[N];
int main(){
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		int t2=0;
		for(int j=i;j<n;j++){
			if(s[j]=='(')t2++;else t2--;
			b[i][j]=min(b[i][j-1],t2);
		}
		int t=0;
		if(s[i]==')')t=-1;else t=1;
		e[i+1]=e[i]+t;
	}
	for(int i=0;i<n;i++)d[n][i]=n,d[i][0]=i-1;
	for(int i=n-1;i>=0;i--)for(int j=1;j<=n;j++){
		if(s[i]=='?'){
			if(j==1)d[i][j]=i;else d[i][j]=d[i+1][j-1];
		}else{
			d[i][j]=d[i+1][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int t=0,q=0,a=0,c=0,t1=0;
		for(int j=i;j<n;j++){
			if(s[j]==')')t1--;else t1++;
			a=min(a,t1);
			if(s[j]=='(')t++;
			else if(s[j]==')')t--;
			else q++;
			if((t+q)%2)continue;
			int x=(q-t)/2,r=d[i][x];
			if(x<0||x>q||r>j)continue;
			c=e[r+1]-e[i];
			if(q==0){
				if(t==0&&a==0){
//					printf("%d %d\n",i,j);
					ans++;
				}
			}else if(a>=0&&c+b[r+1][j]>=0){
//				printf("%d %d\n",i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}