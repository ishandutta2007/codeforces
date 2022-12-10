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

const int N=10000+19;

char s[N];
int vis[N],wei[N][26],vis2[N][26],ok[26];
int n,Time,ans;

int main(){
	scanf("%s",s);
	n=strlen(s);
	For(i,0,n) s[i+n]=s[i];
	For(i,0,n) if (!vis[i]){
		Time++;
		For(j,i,n) if (!vis[j]&&s[j]==s[i]){
			vis[j]=1;
			For(k,0,n){
				if (vis2[k][s[j+k]-'a']!=Time){
					vis2[k][s[j+k]-'a']=Time;
				} else{
					wei[k][s[j+k]-'a']=Time;
				}
			}
		}
		int res=0;
		For(k,0,n){
			int tmp=0;
			For(x,0,26) if (vis2[k][x]==Time&&wei[k][x]!=Time) tmp++;
			res=max(res,tmp);
		}
		ans+=res;
	}
	printf("%.10lf\n",1.0*ans/n);
}