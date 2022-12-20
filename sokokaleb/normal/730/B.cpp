#include <bits/stdc++.h>

using namespace std;

int i,j,n,t,x,y;
vector<int> maxim,minim;
char s[107];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		if (n == 1) {
			printf("! %d %d\n",1,1);
			fflush(stdout);
		} else {
			maxim.clear();
			minim.clear();
			for (i=1 ; i+1<=n ; i+=2) {
				printf("? %d %d\n",i,i+1);
				fflush(stdout);
				
				scanf("%s",&s);
				if (s[0] == '<') {
					minim.push_back(i);
					maxim.push_back(i+1);
				} else {
					minim.push_back(i+1);
					maxim.push_back(i);
				}
			}
			
			if (n % 2 == 1) {
				maxim.push_back(n);
				minim.push_back(n);
			}
			
			x = maxim[0];	
			for (i=1 ; i<maxim.size() ; i++) {
				printf("? %d %d\n",x,maxim[i]);
				fflush(stdout);
				
				scanf("%s",&s);
				if (s[0] == '<') x = maxim[i];
			}
			
			y = minim[0];
			for (i=1 ; i<minim.size() ; i++) {
				printf("? %d %d\n",y,minim[i]);
				fflush(stdout);
				
				scanf("%s",&s);
				if (s[0] == '>') y = minim[i];
			}
			
			printf("! %d %d\n",y,x);
			fflush(stdout);
		}
	}
}