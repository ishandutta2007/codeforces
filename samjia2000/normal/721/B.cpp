#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long long LL;
typedef double db;

const int N = 110;

int ans1,ans2;
int n,k;
char s[N][N],fi[N];
int len[N],lf;

int main(){
	scanf("%d%d",&n,&k);
	fo(i,1,n){
		scanf("%s",s[i]+1);
		fo(j,1,N-1)
		if ((s[i][j]<'0'||s[i][j]>'9')&&(s[i][j]<'a'||s[i][j]>'z')&&(s[i][j]<'A'||s[i][j]>'Z'))
		{len[i]=j-1;break;}
	}
	int ss=0,s1=0;
	scanf("%s",fi+1);
	fo(i,1,N-1)
	if ((fi[i]<'0'||fi[i]>'9')&&(fi[i]<'a'||fi[i]>'z')&&(fi[i]<'A'||fi[i]>'Z')){
		lf=i-1;
		break;
	}
	fo(i,1,n)
	if (len[i]<lf)ss++;
	else
		if (len[i]==lf){
			bool bz=1;
			fo(j,1,lf)
			if (fi[j]!=s[i][j]){
				bz=0;
				break;
			}
			if (!bz)s1++;
		}
	printf("%d %d\n",ss/k*5+ss+1,(ss+s1)/k*5+ss+s1+1);
	return 0;
}