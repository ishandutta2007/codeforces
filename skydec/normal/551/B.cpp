#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,p,k,Suma,Sumb,A[N],B[N],C[N];
char a[N],b[N],c[N];
int main()
{
	 scanf("%s",a); int len=strlen(a);
	 for (i=0;i<len;++i) A[a[i]-'a']++;
	 scanf("%s",b); len=strlen(b);
	 for (i=0;i<len;++i) B[b[i]-'a']++;
	 scanf("%s",c); len=strlen(c);
	 for (i=0;i<len;++i) C[c[i]-'a']++;
	 for (i=0;i<=N;++i)
  {
  	     for (j=0;j<26;++j)
  	       if (B[j]*i>A[j]) break;
  	     if (j<26) break;
  	     int Max=10000000;
  	     for (j=0;j<26;++j) A[j]-=B[j]*i;
  	     for (j=0;j<26;++j)
  	       if (C[j])
  	         Max=min(Max,A[j]/C[j]);
  	     if (i+Max>Suma+Sumb) Suma=i,Sumb=Max;
  	     for (j=0;j<26;++j) A[j]+=B[j]*i;
  }
    for (i=0;i<26;++i) A[i]-=B[i]*Suma+C[i]*Sumb;
    for (i=1;i<=Suma;++i) printf("%s",b);
    for (i=1;i<=Sumb;++i) printf("%s",c);
    for (i=0;i<26;++i)
      for (j=1;j<=A[i];++j) putchar('a'+i);
}