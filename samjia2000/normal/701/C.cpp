#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#include<map>
#define maxn 100005
using namespace std;

map<char,int> m;

int n,ans,v;

string s;

int main(){
	scanf("%d",&n);
	cin>>s;
	fo(i,0,n-1) {if (m[s[i]]==0) v++;m[s[i]]++;}
	m.clear();
	int head=1,tot=0;
	ans=n;
	fo(i,1,n) {
		if (m[s[i-1]]==0) tot++;
		m[s[i-1]]++;
		while (m[s[head-1]]>1){m[s[head-1]]--;head++;}
		if (tot==v) ans=min(ans,i-head+1);
	}
	printf("%d\n",ans);
	return 0;
}