#include <cstdio>
char s[5];
struct Card{
	int num;
	int value;
	friend bool operator ==(Card p,Card q){
		return p.num==q.num||p.value==q.value;
	}
	void read(){
		scanf("%s",s+1);
		if(s[1]=='A'){
			num=1;
		}
		else if(s[1]=='T'){
			num=10;
		}
		else if(s[1]=='J'){
			num=11;
		}
		else if(s[1]=='Q'){
			num=12;
		}
		else if(s[1]=='K'){
			num=13;
		}
		else{
			num=s[1]-'0';
		}
		if(s[2]=='D'){
			value=1;
		}
		else if(s[2]=='C'){
			value=2;
		}
		else if(s[2]=='S'){
			value=3;
		}
		else{
			value=4;
		}
	}
}a[10],desk;
int main(){
	desk.read();
	for(int i=1;i<=5;i++){
		a[i].read();
		if(a[i]==desk){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}