

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
typedef long long ll;
using namespace std;




int main(){
    char s[55];scanf("%s",s);
    int len=strlen(s);
    int ans=0;
    for(int i=0;i<len;i++){
        if(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o')ans++;
        else if(s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')ans++;
    }
    printf("%d",ans);
    return 0;
}