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
#include<functional>

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

const int N=3000+19;

char s[N][N];
int A[N],id[N];
int n,m,a,b,sum;

bool check(){
	int sum=0,top=0;
	For(i,1,n+1){
		sum+=A[i];
		top+=2*(n-i);
		if (sum>top) return 0;
	}
	if (sum!=top) return 0;
	For(i,1,n) if (A[i]<A[i+1]) return 0;
	return 1;
}
bool cmp(int a,int b){
	return A[a]>A[b];
}
void Work(int x){
	if (x==n) return;
	sort(id+x,id+n+1,cmp);
	if (A[id[x]]&1){
		int k=(A[id[x]]-1)/2;
		for (int i=n;i>x;i--){
			int a=k--;
			if (a>0){
				s[id[x]][id[i]]='W',s[id[i]][id[x]]='L';
			} else if (a==0){
				s[id[x]][id[i]]=s[id[i]][id[x]]='D';A[id[i]]--;
			} else{
				s[id[x]][id[i]]='L',s[id[i]][id[x]]='W';A[id[i]]-=2;
			}
		}
	} else{
		int k=A[id[x]]/2;
		for (int i=n;i>x;i--)
			if (k-->0){
				s[id[x]][id[i]]='W',s[id[i]][id[x]]='L';
			} else{
				s[id[x]][id[i]]='L',s[id[i]][id[x]]='W';A[id[i]]-=2;
			}
	}
	Work(x+1);
}

int main(){
	n=IN(),m=IN();
	For(i,1,m+1){
		A[i]=IN();
		sum+=A[i];
	}
	if (n>m){
		sum=n*(n-1)-sum;
		a=sum/(n-m);
		b=sum%(n-m);
		For(i,m+1,n+1) if (b-->0) A[i]=a+1;else A[i]=a;
	}
	if (!check()){
		puts("no");
		return 0;
	}
	puts("yes");
	For(i,1,n+1){
		id[i]=i;
		s[i][i]='X';
	}
	Work(1);
	For(i,1,n+1){
		puts(s[i]+1);
	}
}