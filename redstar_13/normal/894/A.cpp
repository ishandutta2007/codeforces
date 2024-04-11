#include <bits/stdc++.h>
using namespace std;
char str[111];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin>>str;
	int cnt=0;
	int len=strlen(str);
	for(int i=0;i<len-2;i++){
		for(int j=i+1;j<len-1;j++){
			for(int k=j+1;k<len;k++){
				if(str[i]=='Q' and str[j]=='A' and str[k]=='Q') cnt++;
			}
		}
	}
	printf("%d",cnt);
	
	return 0;
}