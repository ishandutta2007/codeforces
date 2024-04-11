#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100000 + 10;
int l,r;
void chk(int x) {
    int y = x;
    //printf("x=%d\n", x);
    vector<int> v;
    while(x) {
        v.push_back(x%10); x/=10;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size()-1;i++) {
        if(v[i] == v[i+1]) return;
    }
    printf("%d\n", y);
    exit(0);
}
int main() {
    cin>>l>>r;
    for(int i=l;i<=r;i++) {
        chk(i);
    }
    printf("-1\n");
}