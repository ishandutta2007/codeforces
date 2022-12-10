#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define int long long
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005;
int n,b[N],dq,ans[N];
vector<int> v[100];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=60;j>=0;j--)if(b[i]>>j&1){v[j].push_back(b[i]); break;}
	}
	for(int tot=1;tot<=n;tot++){
		int flag=0;
		for(int i=0;i<60;i++)if((dq>>i&1)==0&&v[i].size()){
			dq^=(ans[tot]=v[i][v[i].size()-1]); v[i].pop_back(); flag=1; break;
		}
		if(!flag){
			puts("No"); return 0;
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++){
		write(ans[i]); putchar(' ');
	}

}