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
#define lf else if

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

int n;
Vi res;

int calc(int x){
	stringstream ss;
	string s;
	ss<<x;
	ss>>s;
	int res=0;
	For(i,0,s.length()) res+=s[i]-'0';
	return res;
}

int main(){
	n=IN();
	For(i,0,1000+1)
		if (i<=n){
			if ((n-i)+calc(n-i)==n) res.pb(n-i);
		}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for (int i:res) printf("%d\n",i);
}