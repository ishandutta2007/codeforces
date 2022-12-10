#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
void Output(int x){
	static int c;
	if (x>=10) Output(x/10);
	while (c<x%10+'0') c++,putchar('+');
	while (c>x%10+'0') c--,putchar('-');
	putchar('.');
}

const int N=100000;

char s[N];
int n,f,x,ans;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f=1;
	For(i,1,n+1)
		if (!isdigit(s[i])){
			ans=ans+f*x;
			f=(s[i]=='+'?1:-1);
			x=0;
		} else{
			x=(x*10+s[i]-'0');
		}
	ans=ans+f*x;
	Output(ans);
}