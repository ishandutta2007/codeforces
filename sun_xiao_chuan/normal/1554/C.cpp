#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,x,y,tmp;
int res;

int main() {
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&n,&m);
    	res=2100000000;
    	tmp=0;
    	for(i=31;i>=1;i--){
    		x=(n&b(i));
    		y=(m&b(i));
    		if(!y){
    			if(x){res=min(res,tmp);}
    			else{res=min(res,tmp+b(i));}
			}
			else{
				if(!x){tmp+=b(i);}
			}
		}
		printf("%d\n",res);
	}
}