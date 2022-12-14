#include <iostream>
#include <algorithm>
#include <vector>

int N, M;

using namespace std;

int main(){
	scanf("%d%d", &N, &M);
	int two = 1;
	for(int i=0; i<N; i++){
		if(two>M)	break;
		two*=2;
	}
	printf("%d", M%two);
}