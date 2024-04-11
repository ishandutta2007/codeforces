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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int x,now;
char s[10];

int main(){
	for (int Qc=IN();Qc--;){
		x=IN(),scanf("%s",s);
		if (s[0]=='W'||s[0]=='E'){
			if (now==0||now==20000){
				puts("NO");
				return 0;
			}
			continue;
		}
		if (s[0]=='N'){
			now-=x;
			if (now<0){
				puts("NO");
				return 0;
			}
		} else{
			now+=x;
			if (now>20000){
				puts("NO");
				return 0;
			}
		}
	}
	puts(now==0?"YES":"NO");
}