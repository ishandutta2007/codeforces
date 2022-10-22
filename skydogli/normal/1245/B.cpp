#include<bits/stdc++.h>
using namespace std;
int T,a,n,c,b;
char ch[105],ans[105];
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int main(){
    scanf("%d",&T);
    while(T--){
    	memset(ans,0,sizeof(ans));
    	scanf("%d",&n);
    	scanf("%d%d%d",&a,&b,&c);
    	scanf("%s",ch+1);
    	int win=0;
    	for(int i=1;i<=n;++i){
    		if(ch[i]=='R'){
    			if(b){
    				b--;
    				win++;
    				ans[i]='P';
				}
			}
			if(ch[i]=='P'){
				if(c){
					c--;
					win++;
					ans[i]='S';
				}
			}
			if(ch[i]=='S'){
				if(a){
					a--;
					win++;
					ans[i]='R';
				}
			}
		}
		if(win>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;++i){
				if(ans[i])putchar(ans[i]);
				else{
					if(a) putchar('R'),a--;
						else if(b)putchar('P'),b--;
							else putchar('S'),c--;
				}
			}
			puts("");
		}
		else puts("NO");
    }
}