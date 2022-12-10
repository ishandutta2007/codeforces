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
typedef vector<string> Vs;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=3e5+19;

struct AC{
	Vi V[N],son[26];
	Vs s;
	ll A[N];
	int pt[N],Fail[N],I[N],O[N];
	int f,w,num,tot;
	void BFS(){
		static int Q[N];
		int f=1,w=0;Q[1]=0;
		while (f>w){
			int x=Q[++w];
			if (x) V[Fail[x]].pb(x);
			For(i,0,26){
				int &u=son[i][x];
				if (u){
					Q[++f]=u;
					if (x) Fail[u]=son[i][Fail[x]];
				} else{
					u=son[i][Fail[x]];
				}
			}
		}
	}
	void DFS(int x){
		I[x]=++tot;
		For(i,0,V[x].size()) DFS(V[x][i]);
		O[x]=tot;
	}
	void Build(){
		For(i,0,num+1){
			V[i].clear();
			Fail[i]=0;
		}
		For(i,0,26){
			son[i].clear();
			son[i].pb(0);
		}
		num=0;tot=0;
		For(t,0,s.size()){
			int x=0;
			For(i,0,s[t].length()){
				char c=s[t][i]-'a';
				if (!son[c][x]){
					son[c][x]=++num;
					For(j,0,26) son[j].pb(0);
				} x=son[c][x];
			}
			pt[t]=x;
		}
		BFS();
		DFS(0);
		For(i,1,tot+1) A[i]=0;
		For(t,0,s.size()){
			A[I[pt[t]]]++;
			A[O[pt[t]]+1]--;
		}
		For(i,1,tot+1) A[i]+=A[i-1];
	}
	ll Query(string s){
		int x=0;
		ll res=0;
		For(i,0,s.length()){
			x=son[s[i]-'a'][x];
			res+=A[I[x]];
		}
		return res;
	}
};

int Log[1<<20];

struct Sol{
	AC A[20];
	int n;
	Sol(){
		For(i,0,20) A[i].Build();
	}
	void Insert(string s){
		n++;int x=Log[n&-n];
		A[x].s.pb(s);
		For(i,0,x){
			For(j,0,A[i].s.size()) A[x].s.pb(A[i].s[j]);
			A[i].s.clear();
			A[i].Build();
		}
		A[x].Build();
	}
	ll Query(string s){
		ll res=0;
		For(i,0,20) res+=A[i].Query(s);
		return res;
	}
} S1,S2;

int n,Qc;
char str[N];
string s;

int main(){
	For(i,0,20) Log[1<<i]=i;
	for (Qc=IN();Qc--;){
		int o=IN();
		scanf("%s",str);
		s=string(str);
		if (o==1) S1.Insert(s);
		if (o==2) S2.Insert(s);
		if (o==3){
			printf("%I64d\n",S1.Query(s)-S2.Query(s));
			fflush(stdout);
		}
	}
}