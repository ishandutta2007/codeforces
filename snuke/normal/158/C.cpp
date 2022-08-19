#include<cstdio>
#include<algorithm>
#include<string>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 3005, INF = 1000000000;

char a[5], s[10100];
int si, ri;

int main(){
	int n;
	scanf("%d",&n);
	
	s[0] = '/';
	si = 1;
	
	rep(i,n){
		scanf("%s",a);
		if(a[0] == 'p'){
			s[si] = '\0';
			printf("%s\n",s);
		} else {
			scanf("%s",s+si);
			ri = si;
			if(s[si] == '/') si = 0;
			for(; s[ri] != '\0'; ri++){
				if(s[ri] == '.'){
					ri++; si-=2;
					while(s[si] != '/') si--;
				} else {
					s[si++] = s[ri];
				}
			}
			s[si++] = '/';
		}
	}
	
	return 0;
}