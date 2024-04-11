#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int y,b,r;
int main(){
    cin>>y>>b>>r;
    int ans=min(min(y,b-1),r-2);
    printf("%d\n", 3*ans+3);
}