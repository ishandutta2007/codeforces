#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;

const int N=50005;
char s[N];
int n;
ull h[N],pw[N];
bool vis[N];

inline void hash(){
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]*29+s[i]-'a'+1;
}
inline ull get(int l,int r){
	if(r>n) return -1;
	if(l>r) return 0;
	return h[r]-h[l-1]*pw[r-l+1];
}
inline int lcp1(int x,int y){
	int l=0,r=y-x;
	while(l<r){
		int mid=l+r+1>>1;
		if(get(x-mid+1,x)==get(y-mid+1,y)) l=mid; else r=mid-1;
	}
	return r;
}
inline int lcp2(int x,int y){
	int l=0,r=y-x;
	while(l<r){
		int mid=l+r+1>>1;
		if(get(x,x+mid-1)==get(y,y+mid-1)) l=mid; else r=mid-1;
	}
	return r;
}

int main(){
	scanf("%s",s+1);n=strlen(s+1);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*29;
	hash();
	for(int i=1;i<=n;i++){
		bool isok=0;
		for(int j=i;j<=n;j+=i){
			if(j+i>n) break;
			if(lcp1(j,j+i)+lcp2(j,j+i)>i){isok=1;break;}
		}
		if(!isok) continue;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=1;j<=n-i;j++)
			if(get(j,j+i-1)==get(j+i,j+i*2-1)){
				for(int k=j;k<=j+i-1;k++)
					vis[k]=1;
				j+=i-1;
			}
		int k=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]) s[++k]=s[j];
		s[k+1]=0;n=k;
		hash();
	}
	printf("%s\n",s+1);
	return 0;
}
/*
birdbirdbirdistheword
*/