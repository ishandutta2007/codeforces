#include<cstdio>
#include<iostream>
#include<string>
using namespace std;


int a[10];
int b[10];

int main() {
    int n,m;
    int smallest = 100;
    int s1 = 10,s2 = 10;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        s1 = min(s1,a[i]);

    }
    for(int j = 0; j < m; j++) {
        scanf("%d",&b[j]);
        s2 = min(s2,b[j]);
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(a[i] == b[j]){
    			smallest = min(smallest, a[i]);
			}
		}
	}
	if(smallest != 100) printf("%d",smallest);
	else printf("%d",min(s1,s2) * 10 + max(s1,s2));

}