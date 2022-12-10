//By hzq84621, contest: Codeforces Round #415 (Div. 1), problem: (B) Glad to see you!, Accepted, #

#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	char c=getchar();int p=1,ret=0;
	while((c<'0')||(c>'9')){if(c=='-')p=-1;c=getchar();}
	while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ret*p;
}
int n,k,ans;
char s[10];
inline int query(int l,int r){
	printf("1 %d %d\n",l,r);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='T';
}
int main(){
	n=read();k=read();
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(query(mid,mid+1))r=mid;
		else l=mid+1;
	}
	ans=l;
	l=1,r=ans-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(query(mid,mid+1))r=mid;
		else l=mid+1;
	}
	if((!query(l,ans))||(ans==1)){
		l=ans+1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(query(mid,mid+1))r=mid;
			else l=mid+1;
		}
	}
	printf("2 %d %d",ans,l);
}