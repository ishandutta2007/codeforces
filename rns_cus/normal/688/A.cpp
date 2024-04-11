
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int n,d;
char s[105];

bool can_beat(){
	for(int i=0; i<n; i++){
		if(s[i]=='0') return true;
	}
	return false;
}

int main(){
	scanf("%d %d",&n,&d); gets(s);
	int cnt=0, ans=0;
	for (int i = 1;i <= d;i++){
		scanf("%s",s);
		if (can_beat()){
			cnt++;
			if(cnt>ans) ans=cnt;
		}else{
			cnt=0;
		}
	}
	printf("%d\n", ans);
	return 0;
}