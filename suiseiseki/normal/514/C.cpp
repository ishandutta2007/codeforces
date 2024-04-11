#include <cstdio>
#include <set>
using namespace std;
const long long Mod=1000000007,Hash=257;
char s[600005];
long long p[600005];
void init(){
	p[0]=1;
	for(int i=1;i<=600000;i++){
		p[i]=(p[i-1]*Hash)%Mod;
	}
}
long long get_hash(char *s){
	int len=0;
	while(s[++len]!='\0');
	len--;
	long long ans=0;
	for(int i=1;i<=len;i++){
		ans=(ans*Hash+s[i])%Mod;
	}
	return ans;
}
set<long long> st;
int main(){
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		st.insert(get_hash(s));
	}
	bool can;
	long long h,x;
	int len;
	for(int i=1;i<=m;i++){
		scanf("%s",s+1);
		h=get_hash(s);
		can=0;
		len=0;
		while(s[++len]!='\0');
		len--;
		for(int j=1;j<=len;j++){
			for(int k='a';k<='c';k++){
				if(k==s[j]){
					continue;
				}
				x=(h+p[len-j]*(k-s[j])+3*Mod)%Mod;
				if(st.find(x)!=st.end()){
					can=1;
					break;
				}
			}
			if(can){
				break;
			}
		}
		if(can){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}