#include <bits/stdc++.h>
using namespace std;

bool ruin(int x){
	return (x%4==0&&x%100!=0)||x%400==0;
}

int y;
int stt;

int main(){
	scanf("%d",&y);
	int now=y;
	while(1){
		stt+=365+ruin(now);
		stt%=7;
		now++;
		if(!stt&&ruin(now)==ruin(y)){
			printf("%d\n",now);
			return 0;
		}
	}
	return 0;
}