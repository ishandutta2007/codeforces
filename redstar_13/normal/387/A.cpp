#include<bits/stdc++.h>



using namespace std;



char s[3][6];

int i, d[3], ans;



int main(){

	

	scanf("%s%s", s[1], s[2]);

	

	for(i=1; i<3; i++) d[i]=60*((s[i][0]-'0')*10+s[i][1]-'0')+(s[i][3]-'0')*10+s[i][4]-'0';

	

	ans=d[1]-d[2];

	if(ans<0) ans+=24*60;

	if(ans/60<10) printf("0");

	printf("%d:", ans/60);

	if(ans%60<10) printf("0");

	printf("%d\n", ans%60);

	return 0;

}