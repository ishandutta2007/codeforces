#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+10;

int t,n;
char s[N],c[N],a[N];

inline int check(char *c){
	int sum = 0;
	for(int i=1;i <= n;i++){
		sum += c[i] == '(' ? 1 : -1;
		if(sum < 0) return 0;
	}
	return sum == 0;
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int cnt = 0;
		for(int i=1;i <= n;i++) if(s[i] == '1') cnt++;
		if(cnt&1){
			puts("NO"); continue;
		}
		for(int i=1;i <= n;i++) if(s[i] == '1'){
			if(cnt) cnt -= 2 , a[i] = c[i] = '(';
			else a[i] = c[i] = ')';
		}
		int b = 0;
		for(int i=1;i <= n;i++) if(s[i] == '0'){
			if(b) a[i] = '(' , c[i] = ')';
			else a[i] = ')' , c[i] = '(';
			b = !b;
		}
		a[n+1] = c[n+1] = 0;
		if(check(a) && check(c)){
			puts("YES");
			printf("%s\n%s\n",a+1,c+1);
		}
		else puts("NO");
	}
}