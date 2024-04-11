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

const int N=100000+19;

int A[N],vis[N];
int n,m,res,mx;
map<string,Vi> M;
char str[N];
string s,t;
multiset<int> S;

bool cmp(int x,int y){
	return A[x]>A[y];
}
bool P(string s){
	int n=s.length();
	For(i,0,n) if (s[i]!=s[n-i-1]) return 0;
	return 1;
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1){
		scanf("%s",str+1);
		s=string(str+1);
		M[s].pb(i);
		if (P(s)) vis[i]=1;
		A[i]=IN();
		S.insert(i);
	}
	for (map<string,Vi>::iterator i=M.begin();i!=M.end();i++){
		sort(i->se.begin(),i->se.end(),cmp);
	}
	for (map<string,Vi>::iterator i=M.begin();i!=M.end();i++)
		if (!P(i->fi)){
			string s=i->fi,t=s;
			reverse(t.begin(),t.end());
			if (s>t||!M.count(t)) continue;
			for (int j=0;j<M[s].size()&&j<M[t].size();j++)
				if (A[M[s][j]]+A[M[t][j]]>0){
					res+=A[M[s][j]]+A[M[t][j]];
					S.erase(M[s][j]);
					S.erase(M[t][j]);
				} else{
					break;
				}
		} else{
			string s=i->fi;
			for (int j=0;j+1<M[s].size();j+=2)
				if (A[M[s][j]]+A[M[s][j+1]]>0){
					res+=A[M[s][j]]+A[M[s][j+1]];
					mx=max(mx,-A[M[s][j+1]]);
					S.erase(M[s][j]);
					S.erase(M[s][j+1]);
				}
		}
	for (int i:S)
		if (vis[i]){
			mx=max(mx,A[i]);
		}
	res+=mx;
	printf("%d\n",res);
}