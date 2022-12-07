#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<memory.h>

using namespace std;

char s[211111],c[211111];
vector<int> v[111];
int n,k;
long long ans;

int find(int o,int x){
	int l,r,c;
	l=0;
	r=v[x].size()-1;
	for(;;){
		if (r-l<6){
			int e=1111111111;
			for (int i=l;i<=r;i++)e=min(e,abs(v[x][i]-o));
			return e;
		}
		c=(l+r)/2;
		if (v[x][c]>o)r=c;else l=c;
	}
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d\n",&k,&n);
	gets(s);
	for (int i=0;i<n;i++)v[s[i]-'a'].push_back(i);
	for (int i=0;i<k;i++){
		ans=0;
		gets(c);
		int nn=strlen(c);
		for (int j=0;j<nn;j++)if (v[c[j]-'a'].size()==0)ans+=nn;else ans+=find(j,c[j]-'a');
		printf("%I64d\n",ans);
	}
	return 0;
}