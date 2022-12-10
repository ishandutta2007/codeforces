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

const int N=200000+19;

struct Point{
	int x,y;
} P[N];
map<pii,int> M;
int n,m,cnt;
ll Ans;

bool cmpx(Point A,Point B) {return A.x<B.x;}
bool cmpy(Point A,Point B) {return A.y<B.y;}

int main(){
	n=IN();
	For(i,1,n+1){
		P[i]=(Point){IN(),IN()};
		M[mp(P[i].x,P[i].y)]++;
	}
	for (map<pii,int>::iterator i=M.begin();i!=M.end();i++){
		Ans-=1ll*i->sec*(i->sec-1)/2;
		//P[++m]=(Point){(i->fir).fir,(i->fir).sec};
	}
	sort(P+1,P+n+1,cmpx);
	For(i,1,n+1)
		if (i!=1&&P[i].x!=P[i-1].x){
			Ans+=1ll*cnt*(cnt-1)/2;
			cnt=1;
		} else cnt++;
	Ans+=1ll*cnt*(cnt-1)/2;
	cnt=0;
	sort(P+1,P+n+1,cmpy);
	For(i,1,n+1)
		if (i!=1&&P[i].y!=P[i-1].y){
			Ans+=1ll*cnt*(cnt-1)/2;
			cnt=1;
		} else cnt++;
	Ans+=1ll*cnt*(cnt-1)/2;
	cnt=0;
	printf("%I64d\n",Ans);
}