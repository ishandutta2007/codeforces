#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[101000];
int main(){
	//freopen("1.in", "r", stdin);
	int n, k, x;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for(int i=0; i<k; i++){
		scanf("%d", &x);
		for(int j=0; j<x; j++){
			scanf("%d", &a[j]);
		}
		if(a[0]!=1){
			cnt+=x;
		}else {
			int j;
			for(j=1; j<x; j++){
				if(a[j]!=a[j-1]+1)break;
			}
			cnt+=x-j+1;
		}
    }
    printf("%d\n", cnt*2-k-1);
    return 0;
}