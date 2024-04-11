/* Codeforces - 719C */
#include <bits/stdc++.h>
using namespace std;

int n,t;
char s[200005];

void jw(int whr){
	s[whr]='0'+10;
	int st=0;
	while(whr&&s[whr]-'0'==10){
		s[whr]=st;
		whr--;
		if(s[whr]=='.'){
			s[whr]=0;
			st='0';
			whr--;
		}
		s[whr]++;
	}
	if(s[0]-'0'==10){
		s[0]='0';
	}
}

int main(){
	scanf("%d%d",&n,&t);
	scanf("%s",s);
	bool st=0;
	for(int i=0;i<n;i++){
		if(s[i]=='.'){
			st=1;
			i++;
		}
		if(!st){
			continue;
		}
		if(s[i]<'4'){
			continue;
		}else if(s[i]>'4'){
			jw(i);
			if(s[0]=='0'){
				printf("1");
			}
			printf("%s",s);
			return 0;
		}else{
			int now=i;
			while(s[i]=='4'){
				i++;
			}
			if(s[i]<'4'){
				continue;
			}else{
				jw(max(now,i-t+1));
				if(s[0]=='0'){
					printf("1");
				}
				printf("%s",s);
				return 0;
			}
		}
	}
	printf("%s",s);
	return 0;
}