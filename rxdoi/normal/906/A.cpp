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

const int N=100000+19;

bool vis[26],tmp[26];
char s[N],opt[10];
int n,ans,chk,l;

int main(){
	n=IN();
	while (n--){
		scanf("%s%s",opt,s);
		if (opt[0]=='!'){
			if (chk==25) ans++;
			memset(tmp,0,sizeof(tmp));
			l=strlen(s);
			For(i,0,l) tmp[s[i]-'a']=1;
			For(i,0,26) if (!tmp[i]){
				if (!vis[i]) vis[i]=1,chk++;
			}
		} lf (opt[0]=='.'){
			memset(tmp,0,sizeof(tmp));
			l=strlen(s);
			For(i,0,l) tmp[s[i]-'a']=1;
			For(i,0,26) if (tmp[i]){
				if (!vis[i]) vis[i]=1,chk++;
			}
		} lf (opt[0]=='?'){
			if (n!=0){
				if (chk==25) ans++;
				if (!vis[s[0]-'a']){
					vis[s[0]-'a']=1;
					chk++;
				}
			}
		}
	}
	printf("%d\n",ans);
}