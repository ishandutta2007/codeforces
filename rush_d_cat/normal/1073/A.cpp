#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n; char s[N];
int main() {
    scanf("%d%s",&n,s+1);
    for(int i=1;i<n;i++){
        if(s[i]!=s[i+1])
            return !printf("YES\n%c%c\n", s[i],s[i+1]);
    }
    return !printf("NO\n");
}