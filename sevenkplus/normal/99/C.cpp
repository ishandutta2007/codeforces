#include<cstdio>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define forf(x) for(a[x]=0;a[x]<6;a[x]++)
map<char,int> A;
int main()
{
    A['R']=0,A['O']=1,A['Y']=2,A['G']=3,A['B']=4,A['V']=5;
    char s[100];int a[100]={0,0,0,0,0,0};
    scanf("%s",s);
    for(int i=0;i<6;i++)a[A[s[i]]]++;
    sort(a,a+6),reverse(a,a+6);
    int S;
    if(a[0]>=5)S=1;else
    if(a[0]==4)S=2;else
    if(a[1]==3)S=2;else
    if(a[0]==3&&a[1]==2)S=3;else
    if(a[0]==3)S=5;else
    if(a[2]==2)S=6;else
    if(a[1]==2)S=8;else
    if(a[0]==2)S=15;else S=30;
    printf("%d\n",S);
    return 0;
}