#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
using namespace std;
const int N = 200000+10;
char s[N];
int main() {
    scanf("%s",s); int n=strlen(s);
    int cnt=0;
    for(int i=0;s[i];i++)if(s[i]=='a')cnt++;
    printf("%d\n", min(2*cnt-1,n));
}