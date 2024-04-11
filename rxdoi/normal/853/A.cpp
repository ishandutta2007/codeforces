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

const int N=300000+19;

struct QType{
	int T,v;
	bool operator < (const QType &B) const{
		return v<B.v;
	}
} A[N];
priority_queue<QType> Q;
int ans[N];
int n,k,c;
ll res;

bool cmp(QType A,QType B){
	return A.T<B.T;
}

int main(){
	n=IN(),k=IN();
	For(i,1,n+1) A[i]=(QType){i,IN()};
	sort(A+1,A+n+1,cmp);
	c=1;
	For(i,k+1,k+n+1){
		for (;c<=n&&A[c].T<=i;c++){
			Q.push(A[c]);
		}
		QType B=Q.top();Q.pop();
		res+=1ll*B.v*(i-B.T);
		ans[B.T]=i;
	}
	cout<<res<<endl;
	For(i,1,n+1) printf("%d ",ans[i]);
	puts("");
}