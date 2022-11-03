#include<bits/stdc++.h>
using namespace std;

char s[55];
int main(){
	scanf("%s",s);
	int ans=0;
	for(int i=0;s[i];i++)if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')ans++;
	printf("%d\n",ans);
	return 0;
}