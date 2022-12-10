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

const int N=1000+19;
string s[N];
int n,Ans=(1<<30)-1;

int Diff(string A,string B){
	int res=0;
	For(i,0,6) res+=(A[i]!=B[i]);
	return res;
}

int main(){
	n=IN();
	For(i,0,n) cin>>s[i];
	if (n==1){
		puts("6");
		return 0;
	}
	For(i,0,n) For(j,i+1,n) Ans=min(Ans,Diff(s[i],s[j]));
	printf("%d\n",(Ans+1)/2-1);
}