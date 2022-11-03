#include<cstdio>
using namespace std;

int main(){
	int n;scanf("%d",&n);
	if(n==0){
		printf("+------------------------+\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|#.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
		return 0;
	}
	if(n==1){
		printf("+------------------------+\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|#.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
		return 0;
	}
	if(n==2){
		printf("+------------------------+\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|D|)\n");
		printf("|O.#.#.#.#.#.#.#.#.#.#.|.|\n");
		printf("|#.......................|\n");
		printf("|#.#.#.#.#.#.#.#.#.#.#.|.|)\n");
		printf("+------------------------+\n");
		return 0;
	}
	n--;
	int m=n/3,k=n%3;
	printf("+------------------------+\n");
	
	printf("|");
	for(int i=0;i<m;i++)printf("O.");
	if(k>=1){
		printf("O.");
		for(int i=m+1;i<11;i++)printf("#.");
	}else{
		for(int i=m;i<11;i++)printf("#.");
	}
	printf("|D|)\n");
	
	printf("|");
	for(int i=0;i<m;i++)printf("O.");
	if(k>=2){
		printf("O.");
		for(int i=m+1;i<11;i++)printf("#.");
	}else{
		for(int i=m;i<11;i++)printf("#.");
	}
	printf("|.|\n");
	
	printf("|O.......................|\n");
	
	printf("|");
	for(int i=0;i<m;i++)printf("O.");
	for(int i=m;i<11;i++)printf("#.");
	printf("|.|)\n");
	
	printf("+------------------------+\n");
	return 0;
}