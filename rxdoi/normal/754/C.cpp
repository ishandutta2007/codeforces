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

const int N=100+19;

map<string,int> M;
string s[N],t[N];
int vis[N][N],f[N][N],pre[N][N];
int id,n,m;
char tmp[10];

string strIN(){
	static char buf[100+19];
	scanf("%s",buf);
	return string(buf);
}
string strIN2(){
	static char buf[100+19];
	gets(buf);
	return string(buf);
}
void Init(){
	id=0;
	M.clear();
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	memset(pre,0,sizeof(pre));
}
bool chk(char c){
	return !isalpha(c)&&!isdigit(c);
}
bool cmp(int i,int j,int k){
	For(x,0,s[j].length()){
		if (k+x>=t[i].length()||t[i][k+x]!=s[j][x]) return 0;
	}
	return k+s[j].length()>=t[i].length()||chk(t[i][k+s[j].length()]);
}
void dfs(int i,int j){
	if (!i) return;
	if (t[i][0]=='?'){
		t[i]=t[i].erase(0,1);
		t[i]=s[j]+t[i];
	}
	dfs(i-1,pre[i][j]);
}
void Main(){
	Init();
	n=IN();
	For(i,1,n+1){
		s[i]=strIN();
		M[s[i]]=++id;
	}
	m=IN();
	//gets(tmp);
	For(i,1,m+1){
		t[i]=strIN2();
		t[i]+=' ';
		if (t[i][0]!='?'){
			int x=0;
			while (t[i][x]!=':') x++;
			vis[i][M[t[i].substr(0,x)]]=1;
			continue;
		}
		For(j,1,n+1){
			vis[i][j]=1;
			For(k,1,t[i].length())
				if (chk(t[i][k-1])&&cmp(i,j,k)){
					vis[i][j]=0;
					break;
				}
		}
	}
	f[0][0]=1;
	For(i,1,m+1){
		For(j,1,n+1)
			if (vis[i][j])
				For(k,0,n+1){
					if (k!=j&&f[i-1][k]){
						f[i][j]=1;
						pre[i][j]=k;
						break;
					}
				}
	}
	For(i,1,n+1)
		if (f[m][i]){
			dfs(m,i);
			For(j,1,m+1){
				t[j]=t[j].erase(t[j].length()-1,1);
				puts(t[j].c_str());
			}
			return;
		}
	puts("Impossible");
}

int main(){
	for (int T=IN();T--;) Main();
}