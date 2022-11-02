#include<bits/stdc++.h>
using namespace std;
int n,x;
bool fl;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x<0){
			x=-x;
			if(x&1){
				if(fl)printf("%d\n",-x/2);
				else printf("%d\n",-(x+1)/2);
				fl^=1;
			}else printf("%d\n",-x/2);
		}
		else{
			if(x&1){
				if(fl)printf("%d\n",(x+1)/2);
				else printf("%d\n",x/2);
				fl^=1;
			}else printf("%d\n",x/2);
		}
	}
}