#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define sort random_shuffle
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
char s[1000010];
struct node{
	char str[21];
	bool dec;
	int len;
}F[100010];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=n;i>=1;--i){
		if(s[i]==s[i+1]){
			char t=F[i+2].str[0];
			if(s[i]>t) F[i]=F[i+2];
			else if(s[i]==t){
				if(F[i+2].dec) F[i]=F[i+2];
				else {
					F[i].dec=0;F[i].len=F[i+2].len+2;
					F[i].str[0]=F[i].str[1]=s[i];
					if(F[i].len>10){
						for(int j=0;j<3;++j) F[i].str[j+2]=F[i+2].str[j];
						F[i].str[5]=F[i].str[6]=F[i].str[7]='.';
						F[i].str[8]=(F[i+2].len<=10?F[i+2].str[F[i+2].len-2]:F[i+2].str[8]);
						F[i].str[9]=(F[i+2].len<=10?F[i+2].str[F[i+2].len-1]:F[i+2].str[9]);
					}
					else{
						F[i].str[0]=F[i].str[1]=s[i];
						for(int j=2;j<F[i].len;++j) F[i].str[j]=F[i+2].str[j-2];
					}
				}
			} 
			else{
				F[i].dec=0;F[i].len=F[i+2].len+2;
				F[i].str[0]=F[i].str[1]=s[i];
				if(F[i].len>10){
					for(int j=0;j<3;++j) F[i].str[j+2]=F[i+2].str[j];
					F[i].str[5]=F[i].str[6]=F[i].str[7]='.';
					F[i].str[8]=(F[i+2].len<=10?F[i+2].str[F[i+2].len-2]:F[i+2].str[8]);
					F[i].str[9]=(F[i+2].len<=10?F[i+2].str[F[i+2].len-1]:F[i+2].str[9]);
				}
				else{
					F[i].str[0]=F[i].str[1]=s[i];
					for(int j=2;j<F[i].len;++j) F[i].str[j]=F[i+2].str[j-2];
				}
			}
		}
		else{
			if(s[i]>F[i+1].str[0]) F[i].dec=1;else if(s[i]==F[i+1].str[0]) F[i].dec=F[i+1].dec;
			F[i].len=F[i+1].len+1;
			F[i].str[0]=s[i];
			if(F[i].len>10){
				for(int j=1;j<5;++j) F[i].str[j]=F[i+1].str[j-1];
				F[i].str[5]=F[i].str[6]=F[i].str[7]='.';
				F[i].str[8]=(F[i+1].len<=10?F[i+1].str[F[i+1].len-2]:F[i+1].str[8]);
				F[i].str[9]=(F[i+1].len<=10?F[i+1].str[F[i+1].len-1]:F[i+1].str[9]);
			} 
			else{
				F[i].str[0]=s[i];
				for(int j=1;j<F[i].len;++j) F[i].str[j]=F[i+1].str[j-1];
			}
		}
	}
	for(int i=1;i<=n;++i) printf("%d %s\n",F[i].len,F[i].str);
	return 0;
}