#include<bits/stdc++.h>

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

const int N=1e5+19;
const int top=1e5;

struct info{
	int A,B,C;
} T[6];
int d[N];
int A,B,C,ans1,ans2,ans3;

void work(int A,int B,int C,int f){
	ans1+=f*d[A]*d[B]*d[C];
	ans2+=f*d[__gcd(A,B)]*d[C];
	ans3+=f*d[__gcd(__gcd(A,B),C)];
}
void Main(){
	A=IN(),B=IN(),C=IN();
	T[0]=(info){A,B,C};
	T[1]=(info){A,C,B};
	T[2]=(info){B,A,C};
	T[3]=(info){B,C,A};
	T[4]=(info){C,A,B};
	T[5]=(info){C,B,A};
	ans1=ans2=ans3=0;
	For(s,1,1<<6){
		int A=0,B=0,C=0;
		For(i,0,6) if (s>>i&1){
			A=__gcd(A,T[i].A);
			B=__gcd(B,T[i].B);
			C=__gcd(C,T[i].C);
		}
		work(A,B,C,__builtin_popcount(s)&1?1:-1);
	}
	ans2-=ans3;
	ans1-=3*ans2+ans3;
	printf("%d\n",ans1/6+ans2+ans3);
}

int main(){
	For(i,1,top+1){
		for (int j=i;j<=top;j+=i) d[j]++;
	}
	for (int T=IN();T--;) Main();
}