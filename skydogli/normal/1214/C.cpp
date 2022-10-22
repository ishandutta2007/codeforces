#include<bits/stdc++.h>
using namespace std;
int n,now;
char ch[300005];
int main(){
	scanf("%d",&n);
	scanf("%s",ch);
	ch[n]=0;
	int loc=n,nod=0;
	for(int i=0;i<n;++i)
		if(ch[i]==')') {loc=i;break;}
	swap(ch[n],ch[loc]);
	for(int i=0;i<=n;++i){
		if(ch[i]=='(')nod++;
		else if(ch[i]==')')nod--;
		if(nod<0) {puts("No");return 0;}
	}
	if(nod!=0)puts("No");
	else puts("Yes");
	return 0;
}