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

const int N=5000+19;

map<string,int> M;
int x[N],y[N],o[N],mn[2],mx[2],n,m;
char s[N];
string str[N],res1,res2;

int calc(int w,int t){
	static int val[N];
	val[0]=t;
	For(i,1,n+1)
		if (!o[i]){
			val[i]=str[i][w]-'0';
		} else{
			if (o[i]==1) val[i]=val[x[i]]^val[y[i]];
			if (o[i]==2) val[i]=val[x[i]]&val[y[i]];
			if (o[i]==3) val[i]=val[x[i]]|val[y[i]];
		}
	int res=0;
	For(i,1,n+1) res+=val[i];
	return res;
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1){
		scanf("%s%*s",s);
		M[string(s)]=i;
		scanf("%s",s);
		if (s[0]=='0'||s[0]=='1'){
			str[i]=string(s);
			continue;
		} else{
			x[i]=M[string(s)];
			scanf("%s",s);
			if (s[0]=='X') o[i]=1;
			if (s[0]=='A') o[i]=2;
			if (s[0]=='O') o[i]=3;
			scanf("%s",s);
			y[i]=M[string(s)];
		}
	}
	For(i,0,m){
		int s0,s1;
		s0=calc(i,0);
		s1=calc(i,1);
		if (s0<s1){
			res1+="0";
			res2+="1";
		}
		if (s0>s1){
			res1+="1";
			res2+="0";
		}
		if (s0==s1){
			res1+="0";
			res2+="0";
		}
	}
	cout<<res1<<endl<<res2<<endl;
}