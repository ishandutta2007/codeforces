#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e5+5;

int n;
LL ans[N];

int main(){
	int s=get();
	int k=0;
	for(int i=1;i*i<=s;i++)
	if(s%i==0){
		ans[++k]=1ll*(s-i)*(s/i)/2+s/i;
		if (i!=s/i){
			int j=s/i;
			ans[++k]=1ll*(s-j)*(s/j)/2+s/j;
		}
	}
	sort(ans+1,ans+1+k);
	fo(i,1,k)printf("%I64d%c",ans[i],i==k?'\n':' ');
	return 0;
}