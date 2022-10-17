/*#include <cstdio>
#include <cstring>
#define Maxn 100000
int nxt[Maxn+5],r[Maxn+5],f[Maxn+5];
char s[Maxn+5];
int n,c;
void init(){
    int k=0;
    n=0;
    while(s[++n]!='\0');
    n--;
    for(int i=2;i<=n;i++){
        while(k&&s[i]!=s[k+1]){
        	k=nxt[k];
		}
        if(s[i]==s[k+1]){
        	k++;
		}
        nxt[i]=k;
    }
}
int main(){
    scanf("%s",str+1);
    init();
    for(int i=nxt[n];i;i=nxt[i]){
        r[c]=i;
        c++;
    }
    memset(f,0,sizeof(f));
    for(int i=n;i>0;i--){
		f[i]++;
		f[nxt[i]]+=f[i];
    }
    printf("%d\n",c+1);
    for(int i=c-1;i>=0;i--){
    	printf("%d %d\n",r[i],f[r[i]]);
	}
    printf("%d %d\n",n,f[n]);
    return 0;
}*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define arg_1 100007
#define arg_2 100009
#define mod_1 1000000007
#define mod_2 1000000009
#define ll long long
#define Maxn 100000
int nxt[Maxn+5],r[Maxn+5],f[Maxn+5];
struct String{
	char s[Maxn+5];
	pair<int,int> hash[Maxn+5];
	int len;
	void read(){
		scanf("%s",s+1);
		len=0;
		while(s[++len]!='\0');
		len--;
		hash[0].first=hash[0].second=0;
		for(int i=1;i<=len;i++){
			hash[i].first=(int)(((ll)hash[i-1].first*arg_1+(s[i]-'a'+1))%mod_1);
			hash[i].second=(int)(((ll)hash[i-1].second*arg_2+(s[i]-'a'+1))%mod_2);
		}
	}
};
char s[Maxn+5];
int n,c;
void init(){
	int k=0;
	while(s[++n]!='\0');
	n--;
	for(int i=2;i<=n;i++){
		while(k&&s[i]!=s[k+1]){
			k=nxt[k];
		}
		if(s[i]==s[k+1]){
			k++;
		}
		nxt[i]=k;
	}
}
int main(){
	scanf("%s",s+1);
	init();
	for(int i=nxt[n];i;i=nxt[i]){
		r[c]=i;
		c++;
	}
	memset(f,0,sizeof(f));
	for(int i=n;i>0;i--){
		f[i]++;
		f[nxt[i]]+=f[i];
	}
	printf("%d\n",c+1);
	for(int i=c-1;i>=0;i--){
		printf("%d %d\n",r[i],f[r[i]]);
	}
	printf("%d %d\n",n,f[n]);
	return 0;
}