#include<cstdio>
#include<cstring>
using namespace std;

char s[200+19],t[200+19];
int cnt['z'+19];
int Aut,Arr;

int main()
{
	scanf("%s%s",s,t);
	for (int i=0;i<strlen(s);i++) cnt[s[i]]++;
	for (int i=0;i<strlen(t);i++) cnt[t[i]]--;
	for (int i='a';i<='z';i++)
	{
		if (cnt[i]<0) {printf("need tree\n");return 0;}
		if (cnt[i]>0) Aut=1;
	}
	if (strlen(s)>strlen(t)) 
		for (int i=0,j=0;i<strlen(s);i++)
		{
			if (s[i]==t[j]) j++;
			if (j==strlen(t)) {printf("automaton\n");return 0;}
		}
	printf("%s\n",Aut?"both":"array");
}