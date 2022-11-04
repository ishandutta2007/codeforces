//file: .cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

int n,num[30],l,ans=0;
char s[1000005];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	getchar();
    scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++)
	{
	    if(s[i]>='a' && s[i]<='z')
	        num[s[i]-'a']++;
	    else
	        if(!num[s[i]-'A'])
	            ans++;
	        else
	            num[s[i]-'A']--;
    }
    printf("%d",ans);
	File_end:
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}