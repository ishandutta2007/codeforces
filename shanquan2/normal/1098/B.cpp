#include<bits/stdc++.h>
using namespace std;

int n,m,x[5],b[300005],now=(1<<30);
char s[5];
string a[300005];
vector<char> ans[300005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)cin>>a[i];
	s[1]='A';s[2]='C';s[3]='T',s[0]='G';
	for(int i=0;i<4;i++)x[i]=i;
	for(int i=0;i<n;i++)ans[i].resize(m+1);
	do{
		int sum=0;
		for(int i=0;i<n;i++){
			int t1=0,t2=0,*d=x+(i%2)*2;
			for(int j=0;j<m;j++){
				int u1=d[j%2],u2=d[(j+1)%2];
				char c1=s[u1],c2=s[u2];
				if(a[i][j]!=c1)t1++;
				if(a[i][j]!=c2)t2++;
			}
			if(t1<t2){
				b[i]=(i%2)*2;
				sum+=t1;
			}else{
				b[i]=(i%2)*2+1;
				sum+=t2;
			}
		}
		if(sum<now){
			now=sum;
			for(int i=0;i<n;i++)for(int j=0;j<m;j++){
				int u=b[i]^(j%2);
				char c=s[x[u]];
				ans[i][j]=c;
			}
		}
	}while(next_permutation(x,x+4));
	
	for(int i=0;i<4;i++)x[i]=i;
	do{
		int sum=0;
		for(int j=0;j<m;j++){
			int t1=0,t2=0,*d=x+(j%2)*2;
			for(int i=0;i<n;i++){
				int u1=d[i%2],u2=d[(i+1)%2];
				char c1=s[u1],c2=s[u2];
				if(a[i][j]!=c1)t1++;
				if(a[i][j]!=c2)t2++;
			}
			if(t1<t2){
				b[j]=(j%2)*2;
				sum+=t1;
			}else{
				b[j]=(j%2)*2+1;
				sum+=t2;
			}
		}
		if(sum<now){
			now=sum;
			for(int i=0;i<n;i++)for(int j=0;j<m;j++){
				int u=b[j]^(i%2);
				char c=s[x[u]];
				ans[i][j]=c;
			}
		}
	}while(next_permutation(x,x+4));
	
//	printf("%d\n",now);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}