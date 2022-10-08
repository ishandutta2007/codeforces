#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;

int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	if (n==1){
		printf("a\na\nb\nb\n");
		return 0;
	}   
	if (n%2==0){
		for (int i=0;i<n/2;i++){
			printf("%c%c",'a'+i%2,'a'+i%2);
		}
		printf("\n");
		printf("c");
		for (int i=0;i<(n-2)/2;i++){
			printf("%c%c",'e'+i%2,'e'+i%2);
		}
		printf("d\n");
		printf("c");
		for (int i=0;i<(n-2)/2;i++){
			printf("%c%c",'g'+i%2,'g'+i%2);
		}
		printf("d\n");
		for (int i=0;i<n/2;i++){
			printf("%c%c",'i'+i%2,'i'+i%2);
		}
		printf("\n");
		return 0;
	}
	if (n%2==1){
		for (int i=0;i<n/2;i++){
			printf("%c%c",'a'+i%2,'a'+i%2);
		}
		printf("c\n");
		for (int i=0;i<n/2;i++){
			printf("%c%c",'d'+i%2,'d'+i%2);
		}
		printf("c\nf");
		for (int i=0;i<n/2;i++){
			printf("%c%c",'g'+i%2,'g'+i%2);
		}
		printf("\nf");
		for (int i=0;i<n/2;i++){
			printf("%c%c",'i'+i%2,'i'+i%2);
		}
		printf("\n");


        
		return 0;
	}


	return 0;
}