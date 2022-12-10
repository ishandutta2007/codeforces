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

string s,t,alp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n,c=1;

void cal(int n){
	if (n==2){
		s="a",t="a";
		return;
	}
	if (n==3){
		s="a",t="aa";
		return;
	}
	if (n&1){
		cal((n-1)/2);
		s+=alp[c];
		t+=alp[c];
		t+=alp[c++];
	} else{
		cal(n-1);
		s+=alp[c];
		t+=alp[c++];
	}
}

int main(){
	n=IN();
	if (n==1) return puts("a a"),0;
	cal(n);
	printf("%s %s\n",(s+t).c_str(),s.c_str());
}