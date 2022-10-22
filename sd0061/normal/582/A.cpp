#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
const int N = 2005;
typedef long long LL;
using namespace std;
int n , res[N];
void work() {
    scanf("%d" , &n);
    map<int , int> Hash;
    for (int i = 0 ; i < n * n ; ++ i) {
        int x ;
        scanf("%d" , &x);
        ++ Hash[x];
    }    
    for (int i = 0 ; i < n ; ++ i) {
        res[i] = (-- Hash.end()) -> first;
        if (!-- Hash[res[i]])
            Hash.erase(res[i]);
        for (int j = 0 ; j < i ; ++ j) {
            int x = __gcd(res[i] , res[j]);
            if (!-- Hash[x])
                Hash.erase(x);
            if (!-- Hash[x])
                Hash.erase(x);            
        }
        printf("%d\n" , res[i]);
    }
}


int main() {
    work();
    return 0;
}