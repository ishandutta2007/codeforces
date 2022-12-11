#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 3e5+5;
const int mo1 = 998244353;
const int mo2 = 1e9+7;

int n;
char s[N];
int lef[N];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fo(i,1,n)lef[i]=n+1;
	LL ans=0;
	fo(i,1,n){
		lef[i]=-1;
		if (i>1)lef[i]=lef[i-1];
		for(int x=i-2;x>=max(1,lef[i]);x-=2)
			if (s[x]==s[i]&&s[x]==s[(x+i)/2]){
				lef[i]=x;
				break;
			}
		if (lef[i]!=-1&&lef[i]<=i)ans=ans+lef[i];
	}
	cout<<ans<<endl;
	return 0;
}