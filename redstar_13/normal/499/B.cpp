#include <bits/stdc++.h>
using namespace std;
#define NN 3030
char fir[NN][20],sec[NN][20],t[NN][20],word[NN][20];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%s%s",fir[i],sec[i]);
		int len=min(strlen(fir[i]),strlen(sec[i]));
		if(len==strlen(fir[i])) strcpy(t[i],fir[i]);
		else strcpy(t[i],sec[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%s",word[i]);
		for(int j=0;j<m;j++){
			if(strcmp(word[i],fir[j])==0 or strcmp(word[i],sec[j])==0) printf("%s ",t[j]);
		}
	}
	return 0;
}