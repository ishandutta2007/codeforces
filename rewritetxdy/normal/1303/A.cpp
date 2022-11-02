#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
char c[110]; 

int main()
{
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		scanf("%s",c+1);
		int cnt = 0,x = 0,f = 0;
		for(int i=1;c[i];i++){
			if(c[i] == '1')
				f = 1,cnt += x,x = 0;
			else if(f == 1)
				x++;
		}
		printf("%d\n",cnt);
	}
}