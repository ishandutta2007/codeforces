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

const int N=200000+19;

multiset<int> S;
int A[N],n,s,res;

int main(){
	n=IN(),s=IN();
	For(i,1,n+1) A[i]=IN();
	if (A[s]) res++;
	if (n==1){
		printf("%d\n",res);
		return 0;
	}
	For(i,1,n+1)
		if (i!=s){
			S.insert(A[i]==0?n+1:A[i]);
		}
	for (int i=1;i<=n;i++){
		if (*S.begin()!=i){
			res++;
			S.erase(--S.end());
		}
		while (!S.empty()&&*S.begin()==i){
			S.erase(S.begin());
		}
		if (S.empty()) break;
	}
	res+=S.size();
	printf("%d\n",res);
}