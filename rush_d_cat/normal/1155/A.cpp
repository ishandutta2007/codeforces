#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=300000+10;
typedef long long LL;
int n; char s[N];
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<n;i++){
        if(s[i]>s[i+1])return !printf("YES\n%d %d\n", i,i+1);
    }
    return !printf("NO\n");
}