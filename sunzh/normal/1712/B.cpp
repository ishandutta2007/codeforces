#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);c=getchar();
	}
	return x;
}
int T,n;
int main(){
    T=read();
    while(T--){
        n=read();
        if(n&1){
            printf("1 ");
            for(int i=2;i<=n;i+=2) printf("%d %d\n",i+1,i);
            printf("\n");
        }
        else{
            for(int i=1;i<=n;i+=2) printf("%d %d\n",i+1,i);
        }
    }
}