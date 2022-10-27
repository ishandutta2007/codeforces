#include <iostream>
#include <cstring>
using namespace std;
int cnt1[27], cnt2[27], cnt3[27];
char s1[102], s2[102], s3[102];
int main()
{
    scanf("%s %s %s", s1+1, s2+1, s3+1);
    int n1 = strlen(s1 + 1);
    int n2 = strlen(s2 + 1);
    int n3 = strlen(s3 + 1);
    for(int i=1;i<=n1;i++)
    {
        cnt1[s1[i] - 'A'] ++;
    }
    for(int i=1;i<=n2;i++)
    {
        cnt2[s2[i] - 'A'] ++;
    }
    for(int i=1;i<=n3;i++)
    {
        cnt3[s3[i] - 'A'] ++;
    }
    int ok = 1;
    for(int i=0;i<26;i++)
    {
        if(cnt1[i]+cnt2[i] != cnt3[i]) ok = 0;
    }
    printf("%s\n", ok?"YES":"NO");
}