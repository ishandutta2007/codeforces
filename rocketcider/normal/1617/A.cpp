#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int cnt[27],m,n,t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		for(ri i=1;i<=26;++i)cnt[i]=0;
		for(ri i=1;i<=n;++i)++cnt[s[i]-'a'+1],s[i]=0;
		if(t[1]=='a'&&t[2]=='b'&&t[3]=='c'&&cnt[1]&&cnt[2]&&cnt[3]){
			for(ri i=1;i<=cnt[1];++i)putchar('a');
			for(ri i=1;i<=cnt[3];++i)putchar('c');
			for(ri i=1;i<=cnt[2];++i)putchar('b');
			for(ri i=4;i<=26;++i)
				for(ri j=1;j<=cnt[i];++j)
					putchar('a'+i-1);
		}
		else{
			for(ri i=1;i<=26;++i)
				for(ri j=1;j<=cnt[i];++j)
					putchar('a'+i-1);
		}
		putchar(10);
		
	}
	return 0;
}