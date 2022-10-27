#include <iostream>
using namespace std;
const int N=200000+10;
int n; char s[N];
int main(){
    scanf("%d%s",&n,s+1);
    int del=n;
    for(int i=1;i<n;i++) {
        if(s[i]>s[i+1]) {
            del=i; break;
        }
    }
    for(int i=1;i<=n;i++)
        if(i!=del) 
            printf("%c", s[i]);
    printf("\n");
}