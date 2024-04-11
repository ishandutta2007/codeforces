#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,op;
int a,b,c,d,e,f;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(a==c&&a==e){
			if(b<f&&f<d){
				printf("%d\n",abs(b-d)+2);continue;
			}
			if(d<f&&f<b){
				printf("%d\n",abs(b-d)+2);continue;
			}
		}
		if(b==d&&b==f){
			if(c<e&&e<a){
				printf("%d\n",abs(a-c)+2);continue;
			}
			if(a<e&&e<c){
				printf("%d\n",abs(a-c)+2);continue;
			}
		}
		printf("%d\n",abs(a-c)+abs(b-d));
	}
}