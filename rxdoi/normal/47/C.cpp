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

string s[6];
struct sol{
	vector<string> V;
	bool operator < (const sol &B) const{
		for (int i=0;i<V.size()&&i<B.V.size();i++)
			if (V[i]!=B.V[i]) return V[i]<B.V[i];
		return V.size()<B.V.size();
	}
	void print(){
		For(i,0,V.size()) puts(V[i].c_str());
	}
} res,tmp;
bool b;

bool chk(int i,int j,char c){
	if (tmp.V[i][j]!='.'&&tmp.V[i][j]!=c) return 0;
	tmp.V[i][j]=c;
	return 1;
}
void work(){
	if (s[3].length()!=s[1].length()+s[5].length()-1) return;
	if (s[2].length()!=s[0].length()+s[4].length()-1) return;
	tmp.V.clear();
	tmp.V.resize(s[3].length());
	For(i,0,tmp.V.size()){
		For(j,0,s[2].length()) tmp.V[i]+='.';
	}
	For(i,0,s[0].length()) if (!chk(0,i,s[0][i])) return;
	For(i,0,s[1].length()) if (!chk(i,0,s[1][i])) return;
	For(i,0,s[2].length()) if (!chk(s[1].length()-1,i,s[2][i])) return;
	For(i,0,s[3].length()) if (!chk(i,s[0].length()-1,s[3][i])) return;
	For(i,0,s[4].length()) if (!chk(s[3].length()-1,s[0].length()-1+i,s[4][i])) return;
	For(i,0,s[5].length()) if (!chk(s[1].length()-1+i,s[2].length()-1,s[5][i])) return;
	if (!b||tmp<res) b=1,res=tmp;
}

int main(){
	For(i,0,6) cin>>s[i];
	sort(s,s+6);
	do{
		work();
	} while (next_permutation(s,s+6));
	if (!b) puts("Impossible");else res.print();
}