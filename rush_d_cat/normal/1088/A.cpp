#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=100000+10;
int x;
int main() {
    cin>>x;
    for(int a=1;a<=x;a++){
        for(int b=1;b<=a;b++){
            if(a%b==0) {
                if(a*b>x && a/b<x) {
                    return !printf("%d %d\n", a,b);
                }
            }
        }
    }
    printf("-1\n");
}