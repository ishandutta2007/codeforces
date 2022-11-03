#include<bits/stdc++.h>
using namespace std;

int n,lst,d;
bool f=1;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		if(i){
			if(i==1)d=x-lst;
			if(x-lst!=d)f=0;
		}
		lst=x;
	}
	if(f)printf("%d\n",lst+d);else printf("%d\n",lst);
	return 0;
}