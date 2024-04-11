#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 20020;

int n;
char ss[N],ans[N],c[N],s[N];
set<int>f[27][27][27],t[27][27][27];

int main()
{
	scanf("%s",ss+1);n = strlen(ss+1);
	for(int i=1;i <= n;i++)
		c[i] = (i-1)%26+'a' , f[c[i]-'a'][26][26].insert(i);
	printf("? %s\n",c+1);
	fflush(stdout);
	scanf("%s",s+1);
	for(int i=1;i <= n;i++) t[s[i]-'a'][26][26].insert(i);
	for(int i=0;i < 26;i++){
    	set<int>::iterator j=f[i][26][26].begin();
    	int cnt = 0;
	    while(j != f[i][26][26].end())
    	    f[i][cnt][26].insert(*j) , c[*j] = 'a'+cnt , cnt = (cnt+1)%26 , j++;
	}
	printf("? %s\n",c+1);
	fflush(stdout);
	scanf("%s",s+1);
	for(int i=0;i < 26;i++){
    	set<int>::iterator j=t[i][26][26].begin();
	    while(j != t[i][26][26].end())
    	    t[i][s[*j]-'a'][26].insert(*j) , j++;
	}
	for(int i=0;i < 26;i++){
		for(int k=0;k < 26;k++){
    		set<int>::iterator j=f[i][k][26].begin();
  		  	int cnt = 0;
	   		while(j != f[i][k][26].end())
    	    	f[i][k][cnt].insert(*j) , c[*j] = 'a'+cnt , cnt = (cnt+1)%26 , j++;
    	}
	}
	printf("? %s\n",c+1);
	fflush(stdout);
	scanf("%s",s+1);
	for(int i=0;i < 26;i++){
		for(int k=0;k < 26;k++){
    		set<int>::iterator j=t[i][k][26].begin();
	   		while(j != t[i][k][26].end())
    	    	t[i][k][s[*j]-'a'].insert(*j) , j++;
    	}
	}
	for(int i=0;i < 26;i++)
		for(int j=0;j < 26;j++)
			for(int k=0;k < 26;k++){
				if(!f[i][j][k].empty()){
					set<int>::iterator x=f[i][j][k].begin();
					set<int>::iterator y=t[i][j][k].begin();
					ans[*x] = ss[*y];
				}
			}
	printf("! %s\n",ans+1);
	return 0;
}