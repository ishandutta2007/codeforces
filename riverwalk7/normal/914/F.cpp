#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
char a[N],ch[N];
int ss[N*26];
bitset<N> ycl[26],ans;
int n,q;
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1; i<=n*26; i++) ss[i]++;
	for(int i=1;i<=n;i++){a[i]-='a'; ycl[a[i]][i]=1; }
	q=read();
	while(q--){
		int op=read();
		if(op==1){
			int pos=read(),ch=getchar()-'a';
			//cout<<pos<<" "<<ch<<" "<<a[pos]<<endl;
			ycl[a[pos]][pos]=0; ycl[ch][pos]=1; a[pos]=ch;
		}else{
			int l=read(),r=read();
			scanf("%s",ch);
			int len=strlen(ch);
			if(r-l+1<len){puts("0"); continue;}
			ans.set();
			ans<<=l-1;
			ans^=ans<<(r-l+2-len);
			for(int i=0;i<len;i++){
				ans=(ans<<1)&ycl[ch[i]-'a'];
			}
			writeln(ans.count());
		}
	}
}