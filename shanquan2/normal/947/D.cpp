#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m,sa[N],sb[N],la[N],lb[N];
char s[N],t[N];
bool check(int a,int b,int ra,int rb){
	if(a==0&&b>0){
		return b%2==0&&ra>rb;
	}
	if(a>b)return 0;
	if(a==b)return ra>=rb&&(ra-rb)%3==0;
	return (b-a)%2==0&&ra>=rb;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;i++){
		sa[i]=sa[i-1]+(s[i]!='A');
		if(s[i]=='A')la[i]=la[i-1]+1;else la[i]=0;
	}
	for(int i=1;i<=m;i++){
		sb[i]=sb[i-1]+(t[i]!='A');
		if(t[i]=='A')lb[i]=lb[i-1]+1;else lb[i]=0;
	}
	int q;scanf("%d",&q);
	while(q--){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int u=sa[b]-sa[a-1],v=sb[d]-sb[c-1];
		int ra=min(la[b],b-a+1),rb=min(lb[d],d-c+1);
		if(check(u,v,ra,rb))printf("1");else printf("0");
//		printf("\n");
	}
	return 0;
}