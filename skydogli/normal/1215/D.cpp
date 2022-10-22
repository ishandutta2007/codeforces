#include<bits/stdc++.h>
using namespace std;
int n,sum1,sum2,flag1,flag2;
char ch[200005];
int main(){
	scanf("%d%s",&n,ch+1);
	for(int i=1;i<=n/2;++i)
		if(ch[i]!='?'){
			sum1+=ch[i]-'0';
		}
		else flag1++;
	for(int i=n/2+1;i<=n;++i)
		 if(ch[i]!='?'){
			sum2+=ch[i]-'0';
		}
		else flag2++;
	bool t=0;
	if(flag1<flag2)swap(flag1,flag2),swap(sum1,sum2);
		int S1=sum1+(flag1-flag2)/2*9;
		if(S1!=sum2){
			t=1;
			puts("Monocarp");
		}
		else puts("Bicarp");	
	return 0;
}