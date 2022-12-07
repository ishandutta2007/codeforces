#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

char a[111111];
int g[111],w[111],k;
pair<int,int>gg[111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	cin >> k;
	int n=strlen(a);
	for (int i=0;i<n;i++)g[a[i]-'a']++;
	for (int i=0;i<26;i++)gg[i]=make_pair(g[i],i);
	sort(gg,gg+26);
	for (int i=0;i<26;i++){
		w[gg[i].second]=min(gg[i].first,k);
		k-=min(gg[i].first,k);
	}
	int ans=0;
	for (int i=0;i<26;i++)ans+=(g[i]-w[i])>0;
	printf("%d\n",ans);
	for (int i=0;i<n;i++)if (w[a[i]-'a']==0){
		putchar(a[i]);
	}else w[a[i]-'a']--;
	puts("");
	return 0;
}