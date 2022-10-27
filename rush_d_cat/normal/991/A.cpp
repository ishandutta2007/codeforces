#include <iostream>
using namespace std;
int a,b,c,n;
int main(){
    cin>>a>>b>>c>>n;
    if(c>a||c>b) return !printf("-1\n");
    if(a>=n||b>=n) return !printf("-1\n");
    if(a+b-c>=n) return !printf("-1\n");
    if(a+b-c<0) return !printf("-1\n");
    printf("%d\n", n-(a+b-c));
}