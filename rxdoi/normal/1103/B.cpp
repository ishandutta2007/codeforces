#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lf else if

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

char s[10];

void work(){
	printf("? %d %d\n",0,1);
	fflush(stdout);
	scanf("%s",s);
	if (s[0]=='x'){
		printf("! %d\n",1);
		fflush(stdout);
		return;
	}
	For(i,0,30){
		printf("? %d %d\n",1<<i,1<<i+1);
		fflush(stdout);
		scanf("%s",s);
		if (s[0]=='x'){
			int x=1<<i;
			for (int j=i-1;~j;j--){
				printf("? %d %d\n",x|1<<j,x);
				fflush(stdout);
				scanf("%s",s);
				if (s[0]=='x') x|=1<<j;
			}
			printf("! %d\n",x+1);
			fflush(stdout);
			return;
		}
	}
}

int main(){
	while (~scanf("%s",s)&&s[0]!='e'){
		work();
	}
}