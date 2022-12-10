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
#define fir first
#define sec second

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

const int N=40;

struct Edge{
	int y,nxt;
} E[5000000];
int Last[N],vis[N],In[N],Q[N],cnt,n,f,w;
string s;

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	In[y]++;
}
void dfs(int x){
	if (!vis[x]) return;
	vis[x]=0;
	putchar(x+'a');
	for (int i=Last[x],y;~i;i=E[i].nxt){
		if (--In[y=E[i].y]==0) dfs(y);
	}
}

int main(){
	memset(Last,-1,sizeof(Last));
	n=IN();
	For(i,0,n){
		cin>>s;
		For(j,0,s.length()-1) Add_Edge(s[j]-'a',s[j+1]-'a');
		For(j,0,s.length()) vis[s[j]-'a']=1;
	}
	For(i,0,26) if (!In[i]) dfs(i);
	puts("");
}