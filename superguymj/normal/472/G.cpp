#include <bits/stdc++.h>
using namespace std;
const unsigned N=2e5;
unsigned a[32][N+31>>5];
unsigned b[32][N+31>>5];
char s[N+1];
static int pc(unsigned n){
    int c;
    __asm__("popcnt %0, %1" : "=r"(c) : "r"(n));
    return c;
}
unsigned get(unsigned p,unsigned q,unsigned len){
	unsigned x=p>>5, y=q>>5, c=0; 
	p&=31; q&=31;
	while(len>=32){
		c+=pc(a[p][x]^b[q][y]);
		++x, ++y;
		len-=32;
	}
	c+=pc((a[p][x]^b[q][y])&((1u<<len)-1));
	return c;
}
int main(){
	int n, m, q, p1, p2, len;
	scanf("%s",s); n=strlen(s);
	for(int i=0;i<32;++i){
    	for(int j=0;i+j<n;++j){
      		if(s[i+j]=='1')
				a[i][j>>5]|=(1<<(j&31));
   		}
  	}
	scanf("%s",s); m=strlen(s);
	for(int i=0;i<32;++i)
    	for(int j=0;i+j<m;++j)
      		if(s[i+j]=='1')
				b[i][j>>5]|=(1<<(j&31));

	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d",&p1,&p2,&len);
		printf("%d\n",get(p1,p2,len));
	}
	return 0;
}