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

char s[N];
int n;
int f[N][15];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	LL ans=0;
	fo(i,1,n){
		int c=s[i]-'0';
		fo(x,0,10)
		if (f[i-1][x]){
			if (x>c){
				int y=(x+10)%11;
				f[i][(y*(y+1)/2+9+c+1)%11]+=f[i-1][x];
			}
		}
		if (c)f[i][c]++;
		fo(x,0,10)ans=ans+f[i][x];
		int stop=1;
	}
	cout<<ans<<endl;
	return 0;
}