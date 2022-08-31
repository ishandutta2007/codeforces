#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=3005;
char a[N];
int n;int f[N];
int g[N];
bool fu(char x){
	if((x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u'))return 0;
	return 1;
}
void out(int x){
	if(!x)return;
	out(g[x]);
	rep(i,g[x]+1,x)putchar(a[i]);
	if(x!=n)putchar(' ');
	else putchar('\n');
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	memset(f,63,sizeof f);
	f[0]=0;
	rep(i,1,n){
		bool same=1;
		int now=0;
		int pp=i;
		per(j,i,1){
			same&=(a[j]==a[pp]);
			if(fu(a[j])){
				++now;
				if(now==1){
					same=1;
					pp=j;
				}
			}
			else{
				now=0;
			}
			if((!same)&&now>=3)break;
			if(f[j-1]+1<f[i]){
				f[i]=f[j-1]+1;
				g[i]=j-1;
			}
		}
	}
	out(n);
	return 0;
}