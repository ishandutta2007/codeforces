#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;

char s[N];
int n,t,len,x=-1,b;

int main(){
	n=IN();t=IN();
	scanf("%s",s+1);
	for (int i=n;i;i--){
		if (s[i]=='.') break;
		if (s[i]>='5'&&s[i]<='9') x=i;
	}
	if (x==-1){
		puts(s+1);
		return 0;
	}
	s[x]=0;t--;b=1;
	for (x--;s[x]!='.'&&b;x--){
		s[x]++;
		if (s[x]>'9'){
			s[x]=0,b=1;
		} else
		if (s[x]=='5'&&t){
			s[x]=0,b=1;t--;
		} else{
			b=0;
		}
	}
	for (x--;x>0&&b;x--){
		s[x]++;
		if (s[x]>'9'){
			s[x]='0',b=1;
		} else{
			b=0;
		}
	}
	if (s[strlen(s+1)]=='.') s[strlen(s+1)]=0;
	if (b){
		s[0]='1';
		puts(s);
	} else{
		puts(s+1);
	}
}