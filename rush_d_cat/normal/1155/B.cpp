#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=200000+10;
int n;char s[N];
vector<int> v1,v2;
int main(){
    scanf("%d%s",&n,s+1);
 
    for(int i=1;i<=n;i++){
        if(s[i]=='8')v2.push_back(i);
        else v1.push_back(i);
    }

    int i=0,j=0,len=n;
    while(len>11){
        if(i<v1.size())++i;
        else ++j;

        if(j<v2.size())++j;
        else ++i;
        len-=2;
    }
    //printf("i=%d,j=%d(%d,%d)\n", i,j,v1[i],v2[j]);
    if(j==v2.size()) return !printf("NO\n");
    if(i==v1.size()) return !printf("YES\n");
    if(v1[i]>v2[j] ){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}