#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

struct node{
	int x,y;
}p[500005],q[500005];
int n,m,a[505][505];
char s[505];

inline ll check(node a,node b,node c){
	return (ll)(a.x-b.x)*(ll)(c.y-b.y)-(ll)(a.y-b.y)*(ll)(c.x-b.x);
}
inline bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

int main(){
	while(1){
	read(n);m=0;
	if(!n) return 0;
	for(int i=n;i;i--){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
			a[i][j]=s[j]-'0';
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		puts("");
	}*/
	bool isok=0;
	if(a[1][1]==4) p[++m]=(node){0,0},a[1][1]--;
	for(int i=1;i<=n;i++)
		if(a[1][i]==4||a[1][i]==3){
			p[++m]=(node){0,i};
			a[1][i]--;
			a[1][i+1]--;
		}
	for(int i=1;i<=n;i++){
		int id=0;
		for(int j=1;j<=n;j++)
			if(a[i][j]){id=j;break;}
		if(a[i][id]>1){
			p[++m].x=i;p[m].y=id-1;
			a[i][id]--;
		}
		for(int j=id;j<=n;j++){
			if(!a[i][j]) break;
			p[++m].x=i,p[m].y=j;
			a[i][j]--;a[i][j+1]--;
			a[i+1][j]--;a[i+1][j+1]--;
		}
	}
	for(int i=1;i<=m;i++) swap(p[i].x,p[i].y);
	sort(p+1,p+m+1,cmp);
//	for(int i=1;i<=m;i++)
//		printf("%d %d\n",p[i].x,p[i].y);
//	puts("");
	int tot=0,t=1;
	q[1]=p[1],q[2]=p[2];tot=2;
	for(int i=3;i<=m;i++){
		while(tot>t&&check(q[tot-1],q[tot],p[i])<=0) tot--;
		q[++tot]=p[i]; 
	}
	t=tot;q[++tot]=p[m-1];
	for(int i=m-2;i;i--){
		while(tot>t&&check(q[tot-1],q[tot],p[i])<=0) tot--;
		q[++tot]=p[i]; 
	}
	printf("%d\n",tot-1);
	for(int i=1;i<tot;i++) printf("%d %d\n",q[i].x,q[i].y);
	}
}