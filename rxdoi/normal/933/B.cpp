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

ll n;
int k,V[1000];

int main(){
	cin>>n>>k;
	For(i,0,100){
		V[i]+=n%k;
		if (n>0) n=-(n/k);else n=(-n)/k;
	}
	For(i,0,100){
		if (V[i]<0) V[i]+=k,V[i+1]++;
		if (V[i]>=k) V[i]-=k,V[i+1]--;
	}
	int w=99;
	while (V[w]==0) w--;
	printf("%d\n",w+1);
	For(i,0,w+1) printf("%d ",V[i]);
	puts("");
}