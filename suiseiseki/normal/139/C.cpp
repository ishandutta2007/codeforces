#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string a[10005];
char s[10005];
int n,k;
bool check(char c){
	return c=='a'||c=='o'||c=='e'||c=='u'||c=='i';
}
int main(){
	scanf("%d%d",&n,&k);
	int len,cnt;
	for(int i=0;i<(n<<2);i++){
		scanf("%s",s);
		len=0;
		while(s[len++]!='\0');
		len--;
		cnt=0;
		for(int j=len-1;j>=0;j--){
			if(check(s[j])){
				cnt++;
			}
			if(cnt==k){
				a[i]=string(s+j);
				break;
			}
		}
		if(a[i].empty()){
			a[i]+='0'+(i&3);
		}
	}
	bool aabb=1,abba=1,abab=1;
	for(int i=0;i<(n<<2);i+=4){
		aabb&=a[i]==a[i+1]&&a[i+2]==a[i+3];
		abba&=a[i]==a[i+3]&&a[i+1]==a[i+2];
		abab&=a[i]==a[i+2]&&a[i+1]==a[i+3];
	}
	if(aabb&&abba&&abab){
		puts("aaaa");
	}
	else if(aabb){
		puts("aabb");
	}
	else if(abba){
		puts("abba");
	}
	else if(abab){
		puts("abab");
	}
	else{
		puts("NO");
	}
	return 0;
}