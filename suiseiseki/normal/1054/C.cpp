#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
struct node{
    int l,r,v;
}a[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i].l);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].r);
	}
	for(int i=1;i<=n;i++){
		a[i].v=n-a[i].l-a[i].r;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j].v>a[i].v){
				a[i].l--;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(a[j].v>a[i].v){
				a[i].r--;
			}
		}
		if(a[i].l!=0||a[i].r!=0){
			puts("NO");
			return 0;
		}
	}
    puts("YES");
    for(int i=1;i<=n;++i){
    	cout<<a[i].v<<' ';
	}
	puts("");
    return 0;
}