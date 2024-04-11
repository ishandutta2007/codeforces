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

const int N=2e5+19;

char s[N],x,y;
int n,res;
map<char,char> M;

int main(){
	M['R']='L';
	M['L']='R';
	M['U']='D';
	M['D']='U';
	n=IN();
	scanf("%s",s+1);
	For(i,1,n+1){
		if (s[i]==x||s[i]==y) continue;
		if (x&&!y&&M[x]!=s[i]){
			y=s[i];
		} else{
			res++;
			x=s[i];
			y=0;
		}
	}
	printf("%d\n",res);
}