#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000+10;
bool f(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
char s[N],t[N]; int l1,l2;
int main(){
    scanf("%s%s",s+1,t+1);
    l1 = strlen(s+1), l2 = strlen(t+1);
    if (l1 != l2) {
        return !printf("No\n");
    }
    for(int i=1;s[i];i++) {
        if(f(s[i]) != f(t[i])) return !printf("No\n");
    }   
    printf("Yes\n");
}