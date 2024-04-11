#include<cstdio>
#include<cstring>
using namespace std;

char goal[100010],key[400001];
char ch[100001];
int main(){
    int n;
    scanf("%d",&n);
    key[0]='<',key[1]='3';
    int len=2;
    for(int i=0;i<n;i++){
        scanf("%s",ch);
        int l=strlen(ch);
        for(int j=0;j<l;j++)
            key[len+j]=ch[j];
        key[len+l]='<',key[len+l+1]='3';
        len+=l+2;
    }
    scanf("%s",&goal);
    int lg=strlen(goal),i=0,j=0;
    while(i<len && j<lg){
        while(j<lg && goal[j]!=key[i])j++;
        if(j>=lg)break;
        i++,j++;
    }
    if(i<len)printf("no\n");else printf("yes\n");
    return 0;
}