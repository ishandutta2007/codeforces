#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000 + 10; 
int n; char s[N];
int main() {
    scanf("%d%s",&n,s);
    sort(s,s+n); printf("%s\n", s); 
}