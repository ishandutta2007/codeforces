#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define P 1000000007
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
char a[N];int n,A,B,C;
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	int i=1;
	for(;i<=n&&a[i]=='a';++i);
	int j=i;
	for(;j<=n&&a[j]=='b';++j);
	int k=j;
	for(;k<=n&&a[k]=='c';++k);
	A=i-1;B=j-i;C=k-j;
	if(k==n+1&&A>0&&B>0&&(A==C||B==C))puts("YES");else puts("NO");
	return 0;
}