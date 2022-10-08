#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[2000];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='.')
        {
            if(s[i-1]=='9')puts("GOTO Vasilisa.");else
            {
                if(s[i+1]>='5')s[i-1]++;
                s[i]=0;puts(s);
            }
            return 0;
        }
    return 0;
}