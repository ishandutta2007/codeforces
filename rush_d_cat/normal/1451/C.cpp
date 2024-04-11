#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int T,n,k;
char s[N],t[N];
int main() {
	scanf("%d", &T);
	while(T--){
    	scanf("%d%d%s%s",&n,&k,s+1,t+1);
    	int c[30]={0};
    	for(int i=1;s[i];i++) c[s[i]-'a']++;
    	for(int i=1;t[i];i++) c[t[i]-'a']--;
    	bool ok=1;
    	for(int i=0;i<26;i++)if(c[i]%k)ok=0;
    	int s=0;
    	for(int i=0;i<26;i++){
    		s+=c[i]; if(s<0)ok=0;
    	}
    	printf("%s\n", ok?"Yes":"No");
    }
}