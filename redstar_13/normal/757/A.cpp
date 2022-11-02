#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char s[100010],str[]="Bulbsar";
int a[100010];
main(){
#ifndef ONLINE_JUDGE
	freopen("b.txt","r",stdin);
#endif
	int i,p;
   	gets(s);
	memset(a,0,sizeof a);
	p=1e10;
	for(i=0;s[i];i++) a[s[i]]++; 
	a['u']/=2;
	a['a']/=2;
	for(i=0;str[i];i++) p=min(p,a[str[i]]);
	cout<<p<<endl;
}