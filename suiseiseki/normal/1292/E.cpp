#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int Tsk,n,m,x;
char s[100],t[100];
char ch[5]={'O','H','C'};
void ask(){
	printf("? %s\n",t+1);
	fflush(stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		for(int j=1;t[j];j++){
			s[x+j-1]=t[j];
		}
	}
}
void solve1(){
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			memcpy(t,s,n+1);
			t[1]=ch[i];
			t[4]=ch[j];
			ask();
		}
	}
}
void solve2(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if((i==2&&!s[1])||(j==0&&!s[n])||(s[1]&&s[1]!=ch[i])||(s[n]&&s[n]!=ch[j])||(!s[1]&&!s[n]&&i==1&&j==2)){
				continue;
			}
			memcpy(t,s,n+1);
			t[1]=ch[i];
			t[n]=ch[j];
			ask();
		}
	}
	if(!s[1]&&!s[n]){
		s[1]='H';
		s[n]='C';
	}
}
int main(){
	scanf("%d",&Tsk);
	while(Tsk--){
		scanf("%d",&n);
		if(n==-1){
			return 0;
		}
		for(int i=1;i<=70;i++){
			s[i]=t[i]='\0';
		}
		t[1]='C';
		t[2]='C';
		ask();
		t[1]='C';
		t[2]='H';
		ask();
		t[1]='C';
		t[2]='O';
		ask();
		t[1]='H';
		t[2]='O';
		ask();
		if(n==4&&!s[1]&&s[2]&&s[3]&&!s[4]){
			solve1();
		}
		else{
			t[1]='O';
			t[2]='O';
			ask();
			for(int i=2;i<n;i++){
				if(!s[i]){
					s[i]='H';
				}
			}
			if(n==4&&!s[1]&&s[2]=='H'&&s[3]=='H'&&!s[4]){
				t[1]='H';
				t[2]='H';
				t[3]='H';
				ask();
				if(!s[1]){
					s[1]='O';
				}
				if(!s[4]){
					s[4]='C';
				}
			}
			else{
				solve2();
			}
		}
		printf("! %s\n",s+1);
		fflush(stdout);
		scanf("%d",&x);
		if(!x){
			return 0;
		}
	}
	return 0;
}